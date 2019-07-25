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
        MovementContainer generateMovement(QTextStream& ss);
    public:
        EnemyFactory(const char* path);
        void setHero(BaseObject* hero);
        EnemyContainer generate(int time);
    };

}

#endif // ENEMYFACTORY_H
