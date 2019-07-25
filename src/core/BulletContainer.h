#ifndef BULLETCONTAINER_H
#define BULLETCONTAINER_H

#include <QVector>
#include <string>
#include "BaseBullet.h"

namespace STG {

    class BulletContainer{
        //应该是自机子弹跟敌机子弹分开管理，同时便于判断碰撞
    private:
        QVector<BaseBullet*> data;
        int lx,ly,rx,ry;//bullet out of field will be automatically deleted
    public:
        BulletContainer(int lx=0,int ly=0,int rx=2000,int ry=2000);
        void addBullet(BaseBullet* b);
        void addFromContainer(BulletContainer other);
        void update(int milliInterval);
        //void addBulletByString(std::string str);

        int isHitBy(const BaseObject& obj);//判断是否跟什么相撞，返回碰撞数

        int size() const;
        BaseBullet* operator[](int index) const;
            //只读
            //并不想在类外提供修改功能

        BulletContainer(BulletContainer&&);//移动构造防止指针暴毙
        BulletContainer(const BulletContainer& other)=delete;//删除拷贝构造
        void operator=(const BulletContainer& other)=delete;//删除拷贝赋值
        void operator=(BulletContainer&& other);//移动赋值防止指针暴毙
        ~BulletContainer();
    };

}

#endif // BULLETCONTAINER_H
