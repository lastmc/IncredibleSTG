#ifndef HEROOBJECT_H
#define HEROOBJECT_H

#include "BaseObject.h"

namespace STG {

    class HeroObject:public BaseObject{
        //自机
    protected:
        int life;//残机
        int bomb;//符卡
        int power;//灵力（雾
    public:
        HeroObject(int life=2,int bomb=2);
        virtual ~HeroObject();

        int getLife() const;
        int getBomb() const;
        bool alive() const;
    };

}

#endif // HEROOBJECT_H
