#ifndef BONUSBULLET_H
#define BONUSBULLET_H

#include "BaseBullet.h"

namespace STG {

    class BonusBullet : public BaseBullet{
    public:
        BonusBullet(double x,double y,double vx,double vy,double hitR);
        virtual const char* pic() override;
    };

}

#endif // BONUSBULLET_H
