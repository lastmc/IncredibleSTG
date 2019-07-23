#ifndef TESTENEMY_H
#define TESTENEMY_H

#include "BaseEnemyObject.h"
#include "BulletContainer.h"

namespace STG {

    class TestEnemy : public BaseEnemyObject{
    public:
        TestEnemy(BaseObject* hero);
        BulletContainer shoot() override;
    };

}

#endif // TESTENEMY_H
