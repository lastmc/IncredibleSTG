#include "ButterflyEnemy.h"
#include "DirectionBullet.h"
#include "CircleBullet.h"

namespace STG {

    ButterflyEnemy::ButterflyEnemy(double x,double y,BaseObject* hero,MovementContainer mC){
        life=8;
        hitRadius=25;
        posX=x;
        posY=y;
        this->hero=hero;
        mContainer=std::move(mC);
        shootInterval=2000;
    }

    BulletContainer ButterflyEnemy::shoot(){
        BulletContainer c;
        if(moveTime%shootInterval==0 || moveTime%shootInterval==300 || moveTime%shootInterval==600){
            c.addBullet(new DirectionBullet(x(),y(),0,0.3,7));
            c.addBullet(new DirectionBullet(x(),y(),0.2,0.2,7));
            c.addBullet(new DirectionBullet(x(),y(),-0.2,0.2,7));
        }
        if(moveTime%shootInterval==1200){
            c.addBullet(new CircleBullet(x(),y(),400,300,0.3,7));
            c.addBullet(new CircleBullet(x(),y(),-400,300,-0.3,7));
        }
        return c;
    }

}
