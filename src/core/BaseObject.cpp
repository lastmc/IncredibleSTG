#include "BaseObject.h"
#include "ToolFunc.h"

namespace STG {


    double BaseObject::x() const{
        return posX;
    }
    double BaseObject::y() const{
        return posY;
    }
    double BaseObject::vx() const{
        return velocityX;
    }
    double BaseObject::vy() const{
        return velocityY;
    }
    void BaseObject::setX(double x){
        posX=x;
    }
    void BaseObject::setY(double y){
        posY=y;
    }
    void BaseObject::setVx(double vx){
        velocityX=vx;
    }
    void BaseObject::setVy(double vy){
        velocityY=vy;
    }
    void BaseObject::move(int time){
        //按毫秒移动
        posX+=time*velocityX;
        posY+=time*velocityY;
    }

    //Hit Field
    //为了简化处理，采取圆型碰撞判定
    double BaseObject::hitR() const{
        return hitRadius;
    }
    void BaseObject::setHitR(double r){
        hitRadius=r;
    }

    double BaseObject::dist(const BaseObject& other) const{
        return pointDist(posX,posY,other.x(),other.y());
    }
    bool BaseObject::isHitBy(const BaseObject& other) const{
        return dist(other)<hitRadius+other.hitR();
    }

    BaseObject::~BaseObject(){}

}
