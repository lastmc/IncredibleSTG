#include "BaseEnemyObject.h"

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

    void BaseEnemyObject::hit(){
        life--;
    }

}
