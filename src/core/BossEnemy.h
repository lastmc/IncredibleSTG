#ifndef BOSSENEMY_H
#define BOSSENEMY_H

#include "BaseEnemyObject.h"

namespace STG {

    class BossEnemy : public BaseEnemyObject{
    public:
        BossEnemy(double x,double y,BaseObject* hero,MovementContainer mC);
        virtual BulletContainer shoot() override;
        virtual const char* pic() override{
            return ":/pic/Boss.png";
        }
    };

}

#endif // BOSSENEMY_H
