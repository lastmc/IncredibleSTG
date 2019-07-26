#include "GameOverScene.h"

namespace STG {

    GameOverScene::GameOverScene(int score):score(score){
        retry=false;
        exit=false;
    }

    void GameOverScene::paint(QPainter* painter){
        QFont f;
        f.setBold(true);
        f.setPointSize(36);
        painter->setFont(f);
        painter->drawText(QPoint(400,400),"GAME OVER");
        f.setPointSize(14);
        painter->setFont(f);
        if(~score)
            painter->drawText(QPoint(430,450),"Score : "+QString::number(score));
        painter->drawText(QPoint(430,470),"Press R to retry");
        painter->drawText(QPoint(430,490),"Press Esc to exit");

    }
    void GameOverScene::keyPress(int key){
        switch(key) {
        case Qt::Key_R:
            retry=true;
            break;
        case Qt::Key_Escape:
            exit=true;
            break;
        default:
            break;
        }
    }
    void GameOverScene::keyRelease(int key){}

    BaseScene::GameResult GameOverScene::update(int milliInterval){
        if(retry) return BaseScene::Retry;
        if(exit) return BaseScene::MainMenu;
        return BaseScene::Gaming;
    }

}
