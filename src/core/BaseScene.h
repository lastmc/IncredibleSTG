#ifndef BASESCENE_H
#define BASESCENE_H

#include <QPainter>

namespace STG {

    class BaseScene{
    public:
        enum GameResult{
          Gaming,//当前场景正常运行
          GameOver,//死亡，前往GameOverScene
          StageClear,//通关，前往下一关或者GameClearScene
          GamePaused,//暂停中
          Retry,//从头开始，回到第一关
          MainMenu,//回主菜单
          GameStart,//从第一关开始
          Replay,//重播
          ExitGame//退出游戏
        };
        virtual void paint(QPainter* painter)=0;
        virtual void keyPress(int key)=0;
        virtual void keyRelease(int key)=0;
        virtual GameResult update(int milliInteval)=0;

        virtual ~BaseScene()=default;
    };

}

#endif // BASESCENE_H
