#pragma once

class BaseObject{
	//Base of All Flying Object
protected:
	double posX,posY;
	double velocityX,velocityY;
public:
	double x(){
		return posX;
	}
	double y(){
		return posY;
	}
	double vx(){
		return velocityX;
	}
	double vy(){
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
	virtual ~BaseObject()=0;
};
