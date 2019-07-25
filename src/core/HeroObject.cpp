#include "HeroObject.h"
#include "DirectionBullet.h"
#include "CircleBullet.h"

namespace STG {

    HeroObject::HeroObject(int life,int bomb,int shootInterval):BaseObject(),life(life),bomb(bomb),shootInterval(shootInterval){}

    HeroObject::~HeroObject(){}

    int HeroObject::getLife() const{
        return life;
    }
    int HeroObject::getBomb() const{
        return bomb;
    }
    bool HeroObject::alive() const{
        return life>0;
    }
    int HeroObject::getShootInterval() const{
        return shootInterval;
    }
    int HeroObject::getShootCount() const{
        return shootCount;
    }

    void HeroObject::hit(){
        life--;
    }

    BulletContainer HeroObject::shoot(){
        shootCount++;
        BulletContainer bc;
        bc.addBullet(new DirectionBullet(x(),y(),0,-0.5,3));
        bc.addBullet(new DirectionBullet(x(),y(),-0.1,-0.5,3));
        bc.addBullet(new DirectionBullet(x(),y(),0.1,-0.5,3));
        return bc;
    }

}
