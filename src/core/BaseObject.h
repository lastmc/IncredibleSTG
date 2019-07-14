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
	double setX(double x){
		posX=x;
	}
	double setY(double y){
		posY=y;
	}
	double setVx(double vx){
		velocityX=vx;
	}
	double setVy(double vy){
		velocityY=vy;
	}
	virtual ~BaseObject()=0;
};