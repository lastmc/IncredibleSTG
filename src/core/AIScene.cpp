#include "AIScene.h"

namespace STG {

    BaseScene::GameResult AIScene::update(int milliInterval){
        if(gamePaused) return GamePaused;

        info.heroX=hero->x();
        info.heroY=hero->y();
        info.heroLife=hero->getLife();
        info.enemyX.clear();
        info.enemyY.clear();
        info.enemyHitR.clear();
        info.enemyLife.clear();
        for(int i=0;i<enemys.size();i++){
            info.enemyX.push_back(enemys[i]->x());
            info.enemyY.push_back(enemys[i]->y());
            info.enemyHitR.push_back(enemys[i]->getLife());
            info.enemyLife.push_back(enemys[i]->hitR());
        }
        player.setInfo(info);

        keyboardRecord r=player.act();
        keyUp=r.keyUp;
        keyDown=r.keyDown;
        keyLeft=r.keyLeft;
        keyRight=r.keyRight;
        keyShift=r.keyShift;
        keyZ=r.keyZ;

        return gameLogic(milliInterval);
    }

}
