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

        keyboardRecord r=recorder.getFrame(time);
        keyUp=r.keyUp;
        keyDown=r.keyDown;
        keyLeft=r.keyLeft;
        keyRight=r.keyRight;
        keyShift=r.keyShift;
        keyZ=r.keyZ;

        return gameLogic(milliInterval);
    }

}
