#include "HeroObject.h"

namespace STG {

    HeroObject::HeroObject(int life,int bomb):BaseObject(),life(life),bomb(bomb){}

    HeroObject::~HeroObject(){}

    int HeroObject::getLife() const{
        return life;
    }
    int HeroObject::getBomb() const{
        return bomb;
    }
    bool HeroObject::alive() const{
        return life>0;
    }

}
