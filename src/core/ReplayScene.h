#ifndef REPLAYSCENE_H
#define REPLAYSCENE_H

#include "GameScene.h"

namespace STG {

    class ReplayScene : public GameScene{
    public:
        ReplayScene();
        void keyPress(int key) override;
        void keyRelease(int key) override;
        GameResult update(int milliInterval) override;
    };

}

#endif // REPLAYSCENE_H
