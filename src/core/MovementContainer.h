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

        double vx(int time) const;
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
