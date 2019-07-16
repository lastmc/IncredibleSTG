#include "BulletContainer.h"
#include "DirectionBullet.h"

namespace STG {

    BulletContainer::BulletContainer(int lx,int ly,int rx,int ry):lx(lx),ly(ly),rx(rx),ry(ry){}

    void BulletContainer::addBullet(BaseBullet *b){
        data.append(b);
    }

    void BulletContainer::update(int milliInterval){
        for(auto k:data)
            k->move(milliInterval);

        //auto deleting
        int k=size();
        for(int i=0;i<k;){
            if(data[i]->x()<lx || data[i]->x()>rx || data[i]->y()<ly || data[i]->y()>ry){
                delete data[i];
                data.erase(data.begin()+i);
                k--;
            }else i++;
        }
    }

    //void BulletContainer::addBulletByString(std::string str){}//暂时弃用

    bool BulletContainer::isHitBy(const BaseObject& obj){
        for(auto k:data)
            if(k->isHitBy(obj)) return true;
        return false;
    }

    int BulletContainer::size() const{
        return data.size();
    }

    BaseBullet* BulletContainer::operator[](int index) const{
        if(index>=size()) return nullptr;
        return data[index];
    }

    BulletContainer::~BulletContainer(){
        for(auto k:data)
            delete k;
        data.clear();
    }

}
