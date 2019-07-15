#include "GameScene.h"
#include "DirectionBullet.h"

namespace STG {

    GameScene::GameScene(){
        hero=nullptr;
        keyUp=false;
        keyRight=false;
        keyDown=false;
        keyLeft=false;
        keyZ=false;
    }

    void GameScene::initHero(HeroObject* h){
        if(hero) delete hero;
        hero=h;
    }

    void GameScene::addHeroBullet(BaseBullet* b){
        selfBullets.append(b);
    }

    void GameScene::paint(QPainter* painter){
        QPixmap heroPic;
        heroPic.load(":/pic/hero.ico");
        painter->drawPixmap((int)hero->x(),(int)hero->y(),32,32,heroPic);
        QPixmap bulletPic;
        bulletPic.load(":/pic/hero.ico");
        for(auto k:selfBullets){
            painter->drawPixmap((int)k->x(),(int)k->y(),10,10,bulletPic);
        }
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
        default:
            break;
        }
    }

    void GameScene::update(int milliInterval){
        hero->setVx(-0.2*keyLeft+0.2*keyRight);
        hero->setVy(-0.2*keyUp+0.2*keyDown);
        hero->move(milliInterval);
        if(keyZ) addHeroBullet(new DirectionBullet(hero->x(),hero->y(),0,-0.6,3));
        for(auto k:selfBullets) k->move(milliInterval);
    }

    GameScene::~GameScene(){

    }
}
