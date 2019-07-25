#include "FairyEnemy.h"
#include "DirectionBullet.h"

namespace STG {

    FairyEnemy::FairyEnemy(double x,double y,BaseObject* hero,MovementContainer mC){
        life=2;
        hitRadius=12;
        posX=x;
        posY=y;
        this->hero=hero;
        mContainer=std::move(mC);
        shootInterval=1000;
    }

    BulletContainer FairyEnemy::shoot(){
        BulletContainer c;
        if(moveTime%shootInterval==0)
            c.addBullet(new DirectionBullet(x(),y(),hero->x(),hero->y(),0.15,3));
        return c;
    }

}
