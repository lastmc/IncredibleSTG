#include "BonusBullet.h"

namespace STG {

    BonusBullet::BonusBullet(double x,double y,double vx,double vy,double hitR){
        setX(x);
        setY(y);
        setVx(vx);
        setVy(vy);
        setHitR(hitR);
    }

    const char* BonusBullet::pic(){
        return ":/pic/Bonus.png";
    }

}
