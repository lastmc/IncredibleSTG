#include "ReplayScene.h"

namespace STG {

    ReplayScene::ReplayScene(){
        recorder.setRead(true);
    }

    void ReplayScene::keyPress(int key){
        switch(key){
        case Qt::Key_Escape:
            if(cleared) exitFlag=true;
            else gamePaused=!gamePaused;
            break;
        default:
            break;
        }
    }

    void ReplayScene::keyRelease(int key){
        switch(key){
        default:
            break;
        }
    }

    BaseScene::GameResult ReplayScene::update(int milliInterval){
        //Main Logic
        if(gamePaused) return GamePaused;

        time+=milliInterval;

        keyboardRecord r=recorder.getFrame(time);
        keyUp=r.keyUp;
        keyDown=r.keyDown;
        keyLeft=r.keyLeft;
        keyRight=r.keyRight;
        keyShift=r.keyShift;
        keyZ=r.keyZ;

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

}
