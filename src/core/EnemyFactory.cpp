#include "EnemyFactory.h"
#include "DirectionMovement.h"
#include "CircleMovement.h"
#include "FairyEnemy.h"
#include "ButterflyEnemy.h"
#include "BossEnemy.h"

namespace STG {

    MovementContainer EnemyFactory::generateMovement(QTextStream& ss){
        MovementContainer mc;
        QString ctrl,name;
        ss>>ctrl;
        while(ctrl=='*'){
            ss>>name;
            if(name=="Direction"){
                double vx,vy;
                int mtime;
                ss>>vx>>vy>>mtime;
                mc.addMovement(new DirectionMovement(vx,vy,mtime));
            }else if(name=="Circle"){//Relative
                double x,y,deltaX,deltaY,v;
                int time;
                ss>>x>>y>>deltaX>>deltaY>>v>>time;
                mc.addMovement(new CircleMovement(x,y,deltaX,deltaY,v,time));
            }
            ss>>ctrl;
        }
        return mc;
    }

    EnemyFactory::EnemyFactory(const char* path){
        file.setFileName(path);
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        tS.setDevice(&file);
        tS>>buffTime;
    }

    void EnemyFactory::setHero(BaseObject *hero){
        this->hero=hero;
    }

    void EnemyFactory::setBonusContainer(BulletContainer *p){
        bonusC=p;
    }

    bool EnemyFactory::finished() const{
        return tS.atEnd();
    }

    EnemyContainer EnemyFactory::generate(int time){
        EnemyContainer ec;
        if(tS.atEnd()) return ec;
        if(buffTime==time){
            QString ctrl,name;
            tS>>ctrl;
            while(ctrl=='#'){
                tS>>name;
                if(name=="Fairy"){
                    double x,y;
                    int bonus;
                    tS>>x>>y>>bonus;
                    BaseEnemyObject* ptr=new FairyEnemy(x,y,hero,generateMovement(tS));
                    if(bonus) ptr->setBonusContainer(bonusC);
                    ec.addEnemy(ptr);
                }else if(name=="Butterfly"){
                    double x,y;
                    int bonus;
                    tS>>x>>y>>bonus;
                    BaseEnemyObject* ptr=new ButterflyEnemy(x,y,hero,generateMovement(tS));
                    if(bonus) ptr->setBonusContainer(bonusC);
                    ec.addEnemy(ptr);
                }else if(name=="Boss"){
                    double x,y;
                    int bonus;
                    tS>>x>>y>>bonus;
                    BaseEnemyObject* ptr=new BossEnemy(x,y,hero,generateMovement(tS));
                    if(bonus) ptr->setBonusContainer(bonusC);
                    ec.addEnemy(ptr);
                }
                tS>>ctrl;
            }
            if(tS.atEnd()) buffTime=-1;
            else tS>>buffTime;
        }
        return ec;
    }

}
