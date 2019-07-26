#ifndef BUTTERFLYENEMY_H
#define BUTTERFLYENEMY_H

#include "BaseEnemyObject.h"

namespace STG {

    class ButterflyEnemy : public BaseEnemyObject{
    public:
        ButterflyEnemy(double x,double y,BaseObject* hero,MovementContainer mC);
        virtual BulletContainer shoot() override;
        virtual const char* pic() override{
            return ":/pic/Butterfly.png";
        }
    };

}

#endif // BUTTERFLYENEMY_H
