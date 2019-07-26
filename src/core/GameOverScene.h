#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include "BaseScene.h"

namespace STG {

    class GameOverScene : public BaseScene{
    private:
        int score;
        bool retry,exit;
    public:
        GameOverScene(int score=-1);

        void paint(QPainter* painter) override;
        void keyPress(int key) override;
        void keyRelease(int key) override;
        GameResult update(int milliInterval) override;
    };

}

#endif // GAMEOVERSCENE_H
