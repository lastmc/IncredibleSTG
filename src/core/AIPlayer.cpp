#include "AIPlayer.h"

namespace STG {

    void AIPlayer::setInfo(SceneInfo info){
        this->info=info;
    }

    keyboardRecord AIPlayer::act(){
        return keyboardRecord(0,0,0,0,0,1);
    }

}
