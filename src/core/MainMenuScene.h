#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "BaseScene.h"

namespace STG {

    class MainMenuScene : public BaseScene{
    private:
        int select=0;
        bool enter=false;
        enum Selection{
            StartGame,
            ReplayGame,
            ExitGame,
            End//用于mod End得到选项
          };
    public:

        MainMenuScene();

        virtual void paint(QPainter* painter) override;
        virtual void keyPress(int key) override;
        virtual void keyRelease(int key) override;
        virtual GameResult update(int milliInteval) override;
    };

}

#endif // MAINMENUSCENE_H
