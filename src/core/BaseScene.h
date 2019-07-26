#ifndef BASESCENE_H
#define BASESCENE_H

#include <QPainter>

namespace STG {

    class BaseScene{
    public:
        enum GameResult{
          Gaming,GameOver,StageClear,GamePaused,Retry,MainMenu
        };
        virtual void paint(QPainter* painter)=0;
        virtual void keyPress(int key)=0;
        virtual void keyRelease(int key)=0;
        virtual GameResult update(int milliInteval)=0;

        virtual ~BaseScene()=default;
    };

}

#endif // BASESCENE_H
