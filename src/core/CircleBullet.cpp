#include "CircleBullet.h"
#include "ToolFunc.h"
#include <cmath>
#include <QVector>

namespace STG {

    /*
    CircleBullet::CircleBullet(double cx,double cy,double v,double hitR):centerX(cx),centerY(cy),velocity(v){
        setHitR(hitR);
    }*/

    CircleBullet::CircleBullet(double x,double y,double deltaX,double deltaY,double v,double hitR):centerX(x+deltaX),centerY(y+deltaY),velocity(v){
        setX(x);
        setY(y);
        setHitR(hitR);
        radius=pointDist(0,0,deltaX,deltaY);
    }

    void CircleBullet::move(int time){
        double dx=posX-centerX;
        double dy=posY-centerY;
        double alpha=std::acos(dx/radius);
        if(dy>0) alpha=-alpha;//y坐标方向与直角坐标相反
        alpha+=velocity*time/radius;
        dx=radius*std::cos(alpha);
        dy=radius*std::sin(alpha);
        setX(dx+centerX);
        setY(-dy+centerY);//y坐标方向与直角坐标相反
    }

}
