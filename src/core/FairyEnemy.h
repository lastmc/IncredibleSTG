#ifndef FAIRYENEMY_H
#define FAIRYENEMY_H

#include "BaseEnemyObject.h"

namespace STG {

    class FairyEnemy : public BaseEnemyObject{
    public:
        FairyEnemy(double x,double y,BaseObject* hero,MovementContainer mC);
        virtual BulletContainer shoot() override;
        virtual const char* pic() override{
            return ":/pic/Fairy.png";
        }
    };

}

#endif // FAIRYENEMY_H
