#ifndef DIRECTIONMOVEMENT_H
#define DIRECTIONMOVEMENT_H

#include "BaseMovement.h"

namespace STG {

    class DirectionMovement : public BaseMovement{
    private:
        double _vx,_vy;
    public:
        DirectionMovement(double vx,double vy,int time);

        virtual double vx(int time) const override;
        virtual double vy(int time) const override;
    };

}

#endif // DIRECTIONMOVEMENT_H
