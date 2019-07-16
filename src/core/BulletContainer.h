#ifndef BULLETCONTAINER_H
#define BULLETCONTAINER_H

#include <QVector>
#include <string>
#include "BaseBullet.h"

namespace STG {

    class BulletContainer{
        //实质是一个工厂。。顺便把创建也塞进去
        //应该是自机子弹跟敌机子弹分开管理，同时便于判断碰撞
        //但是我还是觉得管理归工厂是真的离谱
    private:
        QVector<BaseBullet*> data;
        int lx,ly,rx,ry;//bullet out of field will be automatically deleted
    public:
        BulletContainer(int lx,int ly,int rx,int ry);
        void addBullet(BaseBullet* b);
        void update(int milliInterval);
        //void addBulletByString(std::string str);

        bool isHitBy(const BaseObject& obj);//判断是否跟什么相撞

        int size() const;
        BaseBullet* operator[](int index) const;
            //只读
            //并不想在类外提供修改功能

        ~BulletContainer();
    };

}

#endif // BULLETCONTAINER_H
