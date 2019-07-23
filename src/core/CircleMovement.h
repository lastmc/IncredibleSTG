#ifndef CIRCLEMOVEMENT_H
#define CIRCLEMOVEMENT_H

#include "BaseMovement.h"

namespace STG {

    class CircleMovement : public BaseMovement{
    private:
        double centerX,centerY,velocity;//centerX,centerY为绝对坐标,velocity正为逆时针
        double radius;//记录半径
        double x,y;//起始坐标
        int interval;//帧率，决定圆周运动精细程度
    public:
        CircleMovement(double x,double y,double deltaX,double deltaY,double v,int mtime,int interval=10);//直接指定起始坐标与圆心
        virtual double dx(int time) const;
        virtual double dy(int time) const;
        virtual double vx(int time) const override;
        virtual double vy(int time) const override;
    };

}

#endif // CIRCLEMOVEMENT_H
