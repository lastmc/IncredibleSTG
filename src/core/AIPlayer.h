#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "SceneInfo.h"
#include "Recorder.h"

namespace STG {

    class AIPlayer{
    private:
        SceneInfo info;
    public:
        void setInfo(SceneInfo info);
        keyboardRecord act();
    };

}

#endif // AIPLAYER_H
