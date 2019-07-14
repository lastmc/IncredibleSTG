#pragma once

#include "ToolFunc.h"

namespace STG {

    class BaseObject{
        //Base of All Flying Object
    protected:
        double posX,posY;
        double velocityX,velocityY;
        double hitRadius;
    public:
        //Position
        double x() const{
            return posX;
        }
        double y() const{
            return posY;
        }
        double vx() const{
            return velocityX;
        }
        double vy() const{
            return velocityY;
        }
        void setX(double x){
            posX=x;
        }
        void setY(double y){
            posY=y;
        }
        void setVx(double vx){
            velocityX=vx;
        }
        void setVy(double vy){
            velocityY=vy;
        }
        virtual void move(double time=1.0){
            //按秒移动
            posX+=time*velocityX;
            posY+=time*velocityY;
        }

        //Hit Field
        //为了简化处理，采取圆型碰撞判定
        double hitR() const{
            return hitRadius;
        }
        void setHitR(double r){
            hitRadius=r;
        }

        double dist(const BaseObject& other) const{
            return pointDist(posX,posY,other.x(),other.y());
        }
        virtual bool isHitBy(const BaseObject& other) const{
            return dist(other)<hitRadius+other.hitR();
        }

        /*Information
        virtual const char* type()=0;
        */

        virtual ~BaseObject()=0;
    };

    BaseObject::~BaseObject(){}

}
