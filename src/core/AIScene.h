#ifndef AISCENE_H
#define AISCENE_H

#include "ReplayScene.h"
#include "SceneInfo.h"
#include "AIPlayer.h"

namespace STG {

    class AIScene : public ReplayScene{
    private:
        SceneInfo info;
        AIPlayer player;
    public:
        GameResult update(int milliInterval) override;
    };

}

#endif // AISCENE_H
