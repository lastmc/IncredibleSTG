#ifndef HEROOBJECT_H
#define HEROOBJECT_H

#include "BaseObject.h"
#include "BulletContainer.h"

namespace STG {

    class HeroObject:public BaseObject{
        //自机
    protected:
        int life;//残机
        int bomb;//符卡
        int power;//灵力（雾
        int shootInterval;//射击间隔，建议是帧时间倍数
        int shootCount;//射击次数
        bool lowSpeedMode;//低速模式
        int godTime=0;
    public:
        HeroObject(int life=4,int bomb=2,int shootInterval=120);
        virtual ~HeroObject() override;

        int getLife() const;
        int getBomb() const;
        int getShootInterval() const;
        int getShootCount() const;
        void lowSpeed(bool enable);//切换高速低速
        bool hit();
        bool alive() const;
        virtual void move(int time) override;
        virtual BulletContainer shoot();
        int getGodTime() const;
        virtual const char* pic() override{
            return ":/pic/Hero.png";
        }
    };

}

#endif // HEROOBJECT_H
