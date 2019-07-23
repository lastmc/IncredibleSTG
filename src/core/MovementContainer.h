#ifndef MOVEMENTCONTAINER_H
#define MOVEMENTCONTAINER_H

#include "BaseMovement.h"
#include <QVector>

namespace STG {

    class MovementContainer{
    private:
        QVector<BaseMovement*> data;
        int time=0;//总时间
    public:
        MovementContainer()=default;

        double vx(int time) const;//由于圆周运动速度难以计算，不要使用这两个方法
        double vy(int time) const;
        int allTime() const;
        void addMovement(BaseMovement* bm);

        void operator=(const MovementContainer& other)=delete;
        MovementContainer(const MovementContainer& other)=delete;
        void operator=(MovementContainer&& other);
        MovementContainer(MovementContainer&& other);
        ~MovementContainer();
    };

}

#endif // MOVEMENTCONTAINER_H
