#ifndef BASEENEMYOBJECT_H
#define BASEENEMYOBJECT_H

#include "BaseObject.h"
#include "MovementContainer.h"
#include "BulletContainer.h"

namespace STG {

    class BaseEnemyObject:public BaseObject{
        //敌机
    protected:
        int life;//生命
        int moveTime=0;//运动时间，同时也控制射击
        MovementContainer mContainer;
        BaseObject* hero;//用于发射自机狙
    public:
        BaseEnemyObject();
        BaseEnemyObject(BaseObject* hero);
        virtual void move(int time) override;
        virtual BulletContainer shoot()=0;
        void hit();
        int getLife() const;
        int getMoveTime() const;
        virtual bool moveFinished() const;
    };

}

#endif // BASEENEMYOBJECT_H
