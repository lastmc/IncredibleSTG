#include "BossEnemy.h"
#include "DirectionBullet.h"
#include "CircleBullet.h"

namespace STG {

    BossEnemy::BossEnemy(double x,double y,BaseObject* hero,MovementContainer mC){
        life=80;
        hitRadius=30;
        posX=x;
        posY=y;
        this->hero=hero;
        mContainer=std::move(mC);
        shootInterval=10000;
    }

    BulletContainer BossEnemy::shoot(){
        BulletContainer c;
        if(moveTime%shootInterval<2000 && moveTime%50==0){
            c.addBullet(new DirectionBullet(x(),y(),(moveTime%550/50-6)*0.03,0.2,7));
            c.addBullet(new DirectionBullet(x(),y(),(moveTime%550/50-6)*0.03+0.1,0.2,7));
            c.addBullet(new DirectionBullet(x(),y(),(moveTime%550/50-6)*0.03-0.1,0.2,7));
        }
        if(moveTime%shootInterval>3000 && moveTime%shootInterval<6000 && moveTime%120==0){
            c.addBullet(new DirectionBullet(this,hero,0.4,3));
            c.addBullet(new CircleBullet(x(),y(),(hero->x()-x())/2,(hero->y()-y())/2,0.2,7));
            c.addBullet(new CircleBullet(x(),y(),(hero->x()-x())/2,(hero->y()-y())/2,-0.2,7));
        }
        if(moveTime%shootInterval>8000 && moveTime%50==0){
            c.addBullet(new DirectionBullet(x(),y(),(moveTime%550/50-6)*0.03,0.2,7));
            c.addBullet(new DirectionBullet(x(),y(),(moveTime%550/50-6)*0.03+0.1,0.2,7));
            c.addBullet(new DirectionBullet(x(),y(),(moveTime%550/50-6)*0.03-0.1,0.2,7));
        }
        return c;
    }

}
