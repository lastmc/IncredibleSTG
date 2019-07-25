#ifndef FAIRYENEMY_H
#define FAIRYENEMY_H

#include "BaseEnemyObject.h"

namespace STG {

    class FairyEnemy : public BaseEnemyObject{
    public:
        FairyEnemy(double x,double y,BaseObject* hero,MovementContainer mC);
        virtual BulletContainer shoot() override;
    };

}

#endif // FAIRYENEMY_H
