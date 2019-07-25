#include "BulletContainer.h"

namespace STG {

    BulletContainer::BulletContainer(int lx,int ly,int rx,int ry):lx(lx),ly(ly),rx(rx),ry(ry){}

    void BulletContainer::addBullet(BaseBullet *b){
        data.append(b);
    }
    void BulletContainer::addFromContainer(BulletContainer other){
        while(other.size()){
            data.append(other[0]);
            other.data.erase(other.data.begin());
        }
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

    int BulletContainer::isHitBy(const BaseObject& obj){
        int num=0;
        if(data.empty()) return 0;
        for(int k=0;k<data.size();)
            if(data[k]->isHitBy(obj)){
                num++;
                delete data[k];
                data.erase(data.begin()+k);
            }else k++;
        return num;
    }

    int BulletContainer::size() const{
        return data.size();
    }

    BaseBullet* BulletContainer::operator[](int index) const{
        if(index>=size()) return nullptr;
        return data[index];
    }

    BulletContainer::BulletContainer(BulletContainer&& other){
        lx=other.lx;
        ly=other.ly;
        rx=other.rx;
        ry=other.ry;
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
        for(int i=0;i<other.size();i++){
            data.append(other[i]);
            other.data[i]=nullptr;
        }
    }
    void BulletContainer::operator=(BulletContainer &&other){
        lx=other.lx;
        ly=other.ly;
        rx=other.rx;
        ry=other.ry;
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
        for(int i=0;i<other.size();i++){
            data.append(other[i]);
            other.data[i]=nullptr;
        }
    }
    BulletContainer::~BulletContainer(){
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
    }

}
