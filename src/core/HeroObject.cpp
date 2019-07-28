#include "HeroObject.h"
#include "DirectionBullet.h"
#include "CircleBullet.h"

namespace STG {

    HeroObject::HeroObject(int life,int bomb,int shootInterval):BaseObject(),life(life),bomb(bomb),shootInterval(shootInterval){
        setHitR(3);
    }

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

    void HeroObject::lowSpeed(bool enable){
        lowSpeedMode=enable;
    }

    bool HeroObject::hit(){
        if(!godTime){
            life--;
            godTime=2000;
            return true;
        }
        return false;
    }

    BulletContainer HeroObject::shoot(){
        shootCount++;
        BulletContainer bc;
        if(lowSpeedMode){
            bc.addBullet(new DirectionBullet(x()-10,y(),0,-0.5,3));
            bc.addBullet(new DirectionBullet(x(),y(),0,-0.5,3));
            bc.addBullet(new DirectionBullet(x()+10,y(),0,-0.5,3));
        }else{
            bc.addBullet(new DirectionBullet(x(),y(),0,-0.5,3));
            bc.addBullet(new DirectionBullet(x(),y(),-0.1,-0.5,3));
            bc.addBullet(new DirectionBullet(x(),y(),0.1,-0.5,3));
        }
        return bc;
    }

    void HeroObject::move(int time){
        if(godTime) godTime-=time;
        BaseObject::move(time);
    }

    int HeroObject::getGodTime() const{
        return godTime;
    }

}
