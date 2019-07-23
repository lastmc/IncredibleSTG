#include "DirectionMovement.h"

namespace STG {

    DirectionMovement::DirectionMovement(double vx,double vy,int mtime):_vx(vx),_vy(vy){
        time=mtime;
    }

    double DirectionMovement::vx(int time) const{
        return _vx;
    }

    double DirectionMovement::vy(int time) const{
        return _vy;
    }

}
