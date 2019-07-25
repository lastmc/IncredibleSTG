#ifndef BASEBULLET_H
#define BASEBULLET_H

#include "BaseObject.h"

namespace STG {

    class BaseBullet : public BaseObject{
    public:
        BaseBullet()=default;
        virtual ~BaseBullet() override=default;
        virtual inline const char* pic() override{
            return ":/pic/Bullet1.png";
        }
    };

}

#endif // BASEBULLET_H
