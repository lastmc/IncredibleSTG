#ifndef STAGECLEARSCENE_H
#define STAGECLEARSCENE_H

#include "BaseScene.h"

namespace STG {

    class StageClearScene : public BaseScene{
    private:
        int score;
        bool exit;
    public:
        StageClearScene(int score=-1);

        void paint(QPainter* painter) override;
        void keyPress(int key) override;
        void keyRelease(int key) override;
        GameResult update(int milliInterval) override;
    };

}

#endif // STAGECLEARSCENE_H
