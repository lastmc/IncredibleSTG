#ifndef ENEMYCONTAINER_H
#define ENEMYCONTAINER_H

#include <QVector>
#include <string>
#include "BaseEnemyObject.h"

namespace STG {

    class EnemyContainer{
        //所有敌机的容器
    private:
        QVector<BaseEnemyObject*> data;
    public:
        EnemyContainer();
        void addEnemy(BaseEnemyObject* b);
        void addFromContainer(EnemyContainer other);
        void update(int milliInterval);
        BulletContainer shoot();
        //void addBulletByString(std::string str);

        bool isHitBy(const BaseObject& obj);//判断是否跟什么相撞

        int size() const;
        BaseEnemyObject* operator[](int index) const;
            //只读
            //并不想在类外提供修改功能

        EnemyContainer(EnemyContainer&&);//移动构造防止指针暴毙
        EnemyContainer(const EnemyContainer& other)=delete;//删除拷贝构造
        void operator=(const EnemyContainer& other)=delete;//删除拷贝赋值
        void operator=(EnemyContainer&& other);//移动赋值防止指针暴毙
        ~EnemyContainer();
    };

}

#endif // ENEMYCONTAINER_H
