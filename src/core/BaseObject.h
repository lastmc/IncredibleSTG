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
        double x() const;
        double y() const;
        double vx() const;
        double vy() const;
        void setX(double x);
        void setY(double y);
        void setVx(double vx);
        void setVy(double vy);
        virtual void move(int time);//按毫秒移动

        //Hit Field
        //为了简化处理，采取圆型碰撞判定
        double hitR() const;
        void setHitR(double r);

        double dist(const BaseObject& other) const;
        virtual bool isHitBy(const BaseObject& other) const;

        /*Information
        virtual const char* type()=0;
        */

        virtual ~BaseObject()=0;
    };

}
