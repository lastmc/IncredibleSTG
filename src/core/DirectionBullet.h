#ifndef DIRECTIONBULLET_H
#define DIRECTIONBULLET_H

#include "BaseBullet.h"

namespace STG {

    class DirectionBullet:public BaseBullet{
        //直线弹幕
    public:
        DirectionBullet(double x,double y,double vx,double vy,double hitR);
    };

}

#endif // DIRECTIONBULLET_H
