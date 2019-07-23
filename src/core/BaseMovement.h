#ifndef BASEMOVEMENT_H
#define BASEMOVEMENT_H

namespace STG {

    class BaseMovement{
        //移动轨迹基类
    protected:
        int time;//总时间
    public:
        virtual double vx(int time) const=0;//获取time时间的vx
        virtual double vy(int time) const=0;//获取time时间的vy
        virtual int allTime() const;//该Movement的总时间
        virtual ~BaseMovement()=default;
    };

}

#endif // BASEMOVEMENT_H
