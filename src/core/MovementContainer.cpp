#include "MovementContainer.h"

namespace STG {

    void MovementContainer::addMovement(BaseMovement* bm){
        data.append(bm);
        time+=bm->allTime();
    }

    int MovementContainer::allTime() const{
        return time;
    }

    double MovementContainer::vx(int time) const{
        if(data.empty()) return 0;
        int k;
        for(k=0;time-data[k]->allTime()>0;k++){
            time-=data[k]->allTime();
            if(k==data.size()-1) return 0;
        }
        return data[k]->vx(time);
    }

    double MovementContainer::vy(int time) const{
        if(data.empty()) return 0;
        int k;
        for(k=0;time-data[k]->allTime()>0;k++){
            time-=data[k]->allTime();
            if(k==data.size()-1) return 0;
        }
        return data[k]->vy(time);
    }


    MovementContainer::MovementContainer(MovementContainer&& other){
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
        for(int i=0;i<other.data.size();i++){
            data.append(other.data[i]);
            other.data[i]=nullptr;
        }
        time=other.time;
    }

    void MovementContainer::operator=(MovementContainer &&other){
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
        for(int i=0;i<other.data.size();i++){
            data.append(other.data[i]);
            other.data[i]=nullptr;
        }
        time=other.time;
    }

    MovementContainer::~MovementContainer(){
        for(auto k:data)
            if(k)
                delete k;
        data.clear();
    }

}
