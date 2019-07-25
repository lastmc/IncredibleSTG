#ifndef DIRECTIONBULLET_H
#define DIRECTIONBULLET_H

#include "BaseBullet.h"

namespace STG {

    class DirectionBullet:public BaseBullet{
        //直线弹幕
    public:
        DirectionBullet(double x,double y,double vx,double vy,double hitR);
        DirectionBullet(double x,double y,double destX,double destY,double v,double hitR);
        DirectionBullet(BaseObject* src,double vx,double vy,double hitR);
        DirectionBullet(BaseObject* src,BaseObject* dst,double v,double hitR);
    };

}

#endif // DIRECTIONBULLET_H
