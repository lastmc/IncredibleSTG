#include "GameScene.h"
#include "DirectionBullet.h"
#include "TestEnemy.h"
#include "DirectionMovement.h"
#include "FairyEnemy.h"

namespace STG {

    GameScene::GameScene()
        :lx(100),ly(40),rx(600),ry(700),time(0),
          selfBullets(BulletContainer(lx,ly,rx,ry)),enemyBullets(BulletContainer(lx,ly,rx,ry)),enemys(EnemyContainer()),
          eFactory(":/gen/Stage1"){
        hero=nullptr;
        keyUp=false;
        keyRight=false;
        keyDown=false;
        keyLeft=false;
        keyZ=false;
        keyShift=false;
        keyX=false;
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
        QPixmap heroPic;
        heroPic.load(":/pic/hero.ico");
        painter->drawPixmap((int)hero->x(),(int)hero->y(),32,32,heroPic);
        for(int i=0;i<enemys.size();i++)
            painter->drawPixmap((int)enemys[i]->x(),(int)enemys[i]->y(),32,32,heroPic);
        QPixmap bulletPic;
        bulletPic.load(":/pic/hero.ico");
        for(int i=0;i<selfBullets.size();i++)
            painter->drawPixmap((int)selfBullets[i]->x(),(int)selfBullets[i]->y(),10,10,bulletPic);
        for(int i=0;i<enemyBullets.size();i++)
            painter->drawPixmap((int)enemyBullets[i]->x(),(int)enemyBullets[i]->y(),10,10,bulletPic);
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

    void GameScene::update(int milliInterval){
        time+=milliInterval;
        hero->setVx(-(keyShift?0.1:0.2)*keyLeft+(keyShift?0.1:0.2)*keyRight);
        hero->setVy(-(keyShift?0.1:0.2)*keyUp+(keyShift?0.1:0.2)*keyDown);
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

        for(int i=0;i<enemys.size();i++)
            if(selfBullets.isHitBy(*enemys[i])){
                enemys[i]->hit();
                qDebug("hit");
            }
    }

    GameScene::~GameScene(){

    }
}
