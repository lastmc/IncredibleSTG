#include "EnemyContainer.h"

namespace STG {

    EnemyContainer::EnemyContainer(){}

    void EnemyContainer::addEnemy(BaseEnemyObject *b){
        data.append(b);
    }
    void EnemyContainer::addFromContainer(EnemyContainer other){
        while(other.size()){
            data.append(other[0]);
            other.data.erase(other.data.begin());
        }
    }

    void EnemyContainer::update(int milliInterval){
        for(auto k:data)
            k->move(milliInterval);

        //auto deleting
        for(int i=0;i<size();)
            if(data[i]->getLife()<=0 || data[i]->moveFinished()){
                delete data[i];
                data.erase(data.begin()+i);
            }else i++;
    }

    BulletContainer EnemyContainer::shoot(){
        BulletContainer c;
        for(auto k:data)
            c.addFromContainer(k->shoot());
        return c;
    }

    bool EnemyContainer::isHitBy(const BaseObject& obj){
        for(auto k:data)
            if(k->isHitBy(obj)) return true;
        return false;
    }

    int EnemyContainer::size() const{
        return data.size();
    }

    BaseEnemyObject* EnemyContainer::operator[](int index) const{
        if(index>=size()) return nullptr;
        return data[index];
    }

    EnemyContainer::EnemyContainer(EnemyContainer&& other){
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
        for(int i=0;i<other.size();i++){
            data.append(other[i]);
            other.data[i]=nullptr;
        }
    }
    void EnemyContainer::operator=(EnemyContainer &&other){
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
        for(int i=0;i<other.size();i++){
            data.append(other[i]);
            other.data[i]=nullptr;
        }
    }
    EnemyContainer::~EnemyContainer(){
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
    }

}
