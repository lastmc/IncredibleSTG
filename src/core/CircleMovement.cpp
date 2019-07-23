#include "CircleMovement.h"
#include "ToolFunc.h"
#include <cmath>

namespace STG {

    CircleMovement::CircleMovement(double x,double y,double deltaX,double deltaY,double v,int mtime,int interval)
        :x(x),y(y),centerX(x+deltaX),centerY(y+deltaY),velocity(v),interval(interval){
        time=mtime;
        radius=pointDist(0,0,deltaX,deltaY);
    }

    double CircleMovement::vx(int time) const{
        return (dx(time+interval)-dx(time))/interval;
    }

    double CircleMovement::vy(int time) const{
        return (dy(time+interval)-dy(time))/interval;
    }

    double CircleMovement::dx(int time) const{
        double dx=x-centerX;
        double dy=y-centerY;
        double alpha=std::acos(dx/radius);
        if(dy>0) alpha=-alpha;//y坐标方向与直角坐标相反
        alpha+=velocity*time/radius;
        dx=radius*std::cos(alpha);
        dy=radius*std::sin(alpha);
        return dx+centerX;
    }

    double CircleMovement::dy(int time) const{
        double dx=x-centerX;
        double dy=y-centerY;
        double alpha=std::acos(dx/radius);
        if(dy>0) alpha=-alpha;//y坐标方向与直角坐标相反
        alpha+=velocity*time/radius;
        dx=radius*std::cos(alpha);
        dy=radius*std::sin(alpha);
        return -dy+centerY;//y坐标方向与直角坐标相反
    }

}
