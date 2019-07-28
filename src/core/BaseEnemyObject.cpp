#include "BaseEnemyObject.h"
#include "BonusBullet.h"

namespace STG {

    BaseEnemyObject::BaseEnemyObject():hero(nullptr){}

    BaseEnemyObject::BaseEnemyObject(BaseObject* hero):hero(hero){}

    int BaseEnemyObject::getLife() const{
        return life;
    }

    int BaseEnemyObject::getMoveTime() const{
        return moveTime;
    }

    void BaseEnemyObject::move(int time){
        moveTime+=time;
        setVx(mContainer.vx(moveTime));
        setVy(mContainer.vy(moveTime));
        BaseObject::move(time);
    }

    bool BaseEnemyObject::moveFinished() const{
        return moveTime>mContainer.allTime();
    }

    void BaseEnemyObject::hit(int num){
        life-=num;
    }

    void BaseEnemyObject::setBonusContainer(BulletContainer *p){
        bonusC=p;
    }

    BaseEnemyObject::~BaseEnemyObject(){
        if(bonusC) bonusC->addBullet(new BonusBullet(x(),y(),0,0.15,18));
    }

}
