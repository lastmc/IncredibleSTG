#include "TestEnemy.h"
#include "DirectionMovement.h"
#include "DirectionBullet.h"

namespace STG {

    TestEnemy::TestEnemy(BaseObject* hero):BaseEnemyObject(hero){
        life=3;
        setHitR(6);
        moveTime=0;
        MovementContainer c;
        c.addMovement(new DirectionMovement(0.1,0.1,30000));
        mContainer=std::move(c);
    }

    BulletContainer TestEnemy::shoot(){
        BulletContainer c;
        if(moveTime%80==0) c.addBullet(new DirectionBullet(x(),y(),hero->x(),hero->y(),0.4,3));
        return c;
    }

}
