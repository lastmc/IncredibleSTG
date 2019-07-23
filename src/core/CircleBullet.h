#ifndef CIRCLEBULLET_H
#define CIRCLEBULLET_H

#include "BaseBullet.h"

namespace STG {

    class CircleBullet : public BaseBullet{
    private:
        double centerX,centerY,velocity;//centerX,centerY为绝对坐标,velocity正为逆时针
        double radius;//记录半径
    public:
        //CircleBullet(double cx,double cy,double v,double hitR);//指定绝对圆心坐标，后续手动指定起始坐标
        CircleBullet(double x,double y,double deltaX,double deltaY,double v,double hitR);//直接指定起始坐标与圆心
        virtual void move(int time) override;
    };

}

#endif // CIRCLEBULLET_H
