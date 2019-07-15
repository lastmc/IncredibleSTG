#ifndef SCENE_H
#define SCENE_H

#include <QVector>
#include "BaseScene.h"
#include "BaseBullet.h"
#include "HeroObject.h"

namespace STG {

    class GameScene:public BaseScene{
    private:
        HeroObject* hero;
        QVector<BaseBullet*> selfBullets;
        bool keyUp,keyDown,keyRight,keyLeft,keyZ;
    public:
        GameScene();
        void initHero(HeroObject* h);
        void addHeroBullet(BaseBullet* b);

        void paint(QPainter* painter) override;
        void keyPress(int key) override;
        void keyRelease(int key) override;
        void update(int milliInterval) override;

        virtual ~GameScene() override;


    };

}

#endif // SCENE_H
