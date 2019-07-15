#ifndef BASESCENE_H
#define BASESCENE_H

#include <QPainter>

namespace STG {

    class BaseScene{
    public:
        virtual void paint(QPainter* painter)=0;
        virtual void keyPress(int key)=0;
        virtual void keyRelease(int key)=0;
        virtual void update(int milliInteval)=0;

        virtual ~BaseScene()=default;
    };

}

#endif // BASESCENE_H
