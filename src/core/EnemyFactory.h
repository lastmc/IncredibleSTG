#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "BaseEnemyObject.h"
#include "EnemyContainer.h"
#include <fstream>
#include <QFile>
#include <QTextStream>

namespace STG {

    class EnemyFactory{
        //从文件加载enemy
    private:
        QFile file;
        QTextStream tS;
        int buffTime;
        BaseObject* hero;
        BulletContainer* bonusC;//bonus container
        MovementContainer generateMovement(QTextStream& ss);
    public:
        EnemyFactory(const char* path);
        void setHero(BaseObject* hero);
        void setBonusContainer(BulletContainer* p);
        bool finished() const;
        EnemyContainer generate(int time);
    };

}

#endif // ENEMYFACTORY_H
