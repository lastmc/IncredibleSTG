#include "GameScene.h"
#include "DirectionBullet.h"
#include "TestEnemy.h"
#include "DirectionMovement.h"
#include "FairyEnemy.h"
#include <cmath>

namespace STG {

    GameScene::GameScene()
        :lx(80),ly(40),rx(590),ry(720),time(0),
          selfBullets(BulletContainer(lx,ly,rx,ry)),enemyBullets(BulletContainer(lx,ly,rx,ry)),bonus(BulletContainer(lx,ly,rx,ry)),
          enemys(EnemyContainer()),eFactory(":/gen/Stage1"){
        hero=nullptr;
        keyUp=false;
        keyRight=false;
        keyDown=false;
        keyLeft=false;
        keyZ=false;
        keyShift=false;
        keyX=false;
        gamePaused=false;
        cleared=false;
        exitFlag=false;
        score=0;
        initHero(new HeroObject());
        eFactory.setBonusContainer(&bonus);
    }

    void GameScene::initHero(HeroObject* h){
        if(hero) delete hero;
        hero=h;
        h->setX(300);
        h->setY(600);
        eFactory.setHero(hero);
    }

    void GameScene::addHeroBullet(BaseBullet* b){
        selfBullets.addBullet(b);
    }

    void GameScene::paint(QPainter* painter){
        //Draw Status
        QFont f;
        f.setBold(true);
        f.setPointSize(14);
        painter->setFont(f);
        painter->drawText(QPoint(700,80),"Life  : "+QString(hero->getLife(),QChar(0x2730)));//✰
        painter->drawText(QPoint(700,100),"Score : "+QString::number(score));
        painter->drawText(QPoint(700,150),"Current Console");
        painter->drawText(QPoint(700,200),keyUp?"Up":"");
        painter->drawText(QPoint(700,220),keyDown?"Down":"");
        painter->drawText(QPoint(700,240),keyLeft?"Left":"");
        painter->drawText(QPoint(700,260),keyRight?"Right":"");
        painter->drawText(QPoint(700,280),keyZ?"Shoot":"");
        painter->drawText(QPoint(700,320),keyShift?"Low Speed Mode":"");
        painter->drawText(QPoint(700,400),hero->getGodTime()?"God Time "+QString::number(hero->getGodTime()):"");
        painter->drawText(QPoint(700,500),gamePaused?"Game Paused":"");
        painter->drawText(QPoint(700,520),cleared?"Stage Clear! Press Esc to exit":"");


        //Draw Bg
        painter->setClipRect(lx,ly,rx-lx,ry-ly);
        QPixmap bg(":/pic/Stage1bg.png");
        painter->drawPixmap(lx,ly,rx-lx,ry-ly,bg,0,1360-time/10%1360,510,680);

        QPixmap heroPic;
        heroPic.load(hero->pic());
        painter->drawPixmap((int)hero->x()-16,(int)hero->y()-25,32,50,heroPic,0,0,32,50);
        for(int i=0;i<enemys.size();i++){
            QPixmap enemyPic(enemys[i]->pic());
            painter->drawPixmap((int)enemys[i]->x()-enemyPic.width()/2,(int)enemys[i]->y()-enemyPic.height()/2,
                                enemyPic.width(),enemyPic.height(),QPixmap(enemys[i]->pic()));
        }
        QPixmap bulletPic;
        for(int i=0;i<selfBullets.size();i++){
            bulletPic.load(selfBullets[i]->pic());
            painter->drawPixmap((int)selfBullets[i]->x()-8,(int)selfBullets[i]->y()-8,16,16,bulletPic);
        }
        for(int i=0;i<enemyBullets.size();i++){
            bulletPic.load(enemyBullets[i]->pic());
            painter->drawPixmap((int)enemyBullets[i]->x()-8,(int)enemyBullets[i]->y()-8,16,16,bulletPic);
        }
        for(int i=0;i<bonus.size();i++)
            painter->drawPixmap((int)bonus[i]->x()-12,(int)bonus[i]->y()-12,24,24,QPixmap(bonus[i]->pic()));

        painter->setClipRect(0,0,painter->device()->width(),painter->device()->height());
    }

    void GameScene::keyPress(int key){
        switch(key){
        case Qt::Key_Up:
            keyUp=true;
            break;
        case Qt::Key_Down:
            keyDown=true;
            break;
        case Qt::Key_Right:
            keyRight=true;
            break;
        case Qt::Key_Left:
            keyLeft=true;
            break;
        case Qt::Key_Z:
            keyZ=true;
            break;
        case Qt::Key_Shift:
            keyShift=true;
            break;
        case Qt::Key_X:
            keyX=true;
            break;
        case Qt::Key_Escape:
            if(cleared) exitFlag=true;
            else gamePaused=!gamePaused;
            break;
        default:
            break;
        }
    }

    void GameScene::keyRelease(int key){
        switch(key){
        case Qt::Key_Up:
            keyUp=false;
            break;
        case Qt::Key_Down:
            keyDown=false;
            break;
        case Qt::Key_Right:
            keyRight=false;
            break;
        case Qt::Key_Left:
            keyLeft=false;
            break;
        case Qt::Key_Z:
            keyZ=false;
            break;
        case Qt::Key_Shift:
            keyShift=false;
            break;
        case Qt::Key_X:
            keyX=false;
            break;
        default:
            break;
        }
    }

    BaseScene::GameResult GameScene::update(int milliInterval){
        //Main Logic
        if(gamePaused) return GamePaused;

        time+=milliInterval;

        recorder.writeFrame(time,keyboardRecord(keyUp,keyDown,keyLeft,keyRight,keyShift,keyZ));

        hero->lowSpeed(keyShift);
        hero->setVx(-(keyShift?0.15:0.3)*keyLeft+(keyShift?0.15:0.3)*keyRight);
        hero->setVy(-(keyShift?0.15:0.3)*keyUp+(keyShift?0.15:0.3)*keyDown);
        hero->move(milliInterval);
        if(hero->x()<lx) hero->setX(lx);
        if(hero->y()<ly) hero->setY(ly);
        if(hero->x()>rx) hero->setX(rx);
        if(hero->y()>ry) hero->setY(ry);

        enemys.addFromContainer(eFactory.generate(time));
        enemys.update(milliInterval);
        enemyBullets.addFromContainer(enemys.shoot());

        if(keyZ && !(time%hero->getShootInterval())) selfBullets.addFromContainer(hero->shoot());
        selfBullets.update(milliInterval);

        enemyBullets.update(milliInterval);

        bonus.update(milliInterval);

        for(int i=0;i<enemys.size();i++){
            int hit=selfBullets.isHitBy(*enemys[i]);
            enemys[i]->hit(hit);
            score+=hit;
        }
        score+=bonus.isHitBy(*hero)*10;


        if(eFactory.finished() && enemys.size()==0){
            if(enemyBullets.size()) enemyBullets=BulletContainer();
            if(!cleared) score+=100+80*hero->getLife();
            cleared=true;
        }
        if(exitFlag) return StageClear;

        if(enemyBullets.isHitBy(*hero) || enemys.isHitBy(*hero)){
            if(hero->hit()){
                if(hero->alive()){
                    selfBullets=BulletContainer();
                    enemyBullets=BulletContainer();
                    hero->setX(300);
                    hero->setY(600);
                }else{
                    return BaseScene::GameOver;
                }
            }
        }
        return BaseScene::Gaming;
    }

    int GameScene::getScore(){
        return score;
    }

    GameScene::~GameScene(){
        recorder.writeToFile();
        delete hero;
    }
}
