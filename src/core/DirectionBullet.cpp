#include "DirectionBullet.h"
#include "ToolFunc.h"
#include <QVector>

namespace STG {

    DirectionBullet::DirectionBullet(double x,double y,double vx,double vy,double hitR){
        setX(x);
        setY(y);
        setVx(vx);
        setVy(vy);
        setHitR(hitR);
    }

    DirectionBullet::DirectionBullet(double x,double y,double destX,double destY,double v,double hitR){
        setX(x);
        setY(y);
        setHitR(hitR);
        double radius=pointDist(x,y,destX,destY);
        setVx(v*(destX-x)/radius);
        setVy(v*(destY-y)/radius);
    }

}
