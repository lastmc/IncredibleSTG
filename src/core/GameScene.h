#ifndef SCENE_H
#define SCENE_H

#include <QVector>
#include "BaseScene.h"
#include "BaseBullet.h"
#include "HeroObject.h"
#include "BulletContainer.h"
#include "BaseEnemyObject.h"
#include "EnemyContainer.h"

namespace STG {

    class GameScene:public BaseScene{
    private:
        HeroObject* hero;
        BulletContainer selfBullets,enemyBullets;
        EnemyContainer enemys;
        bool keyUp,keyDown,keyRight,keyLeft,keyZ,keyShift,keyX;
        int time;
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
