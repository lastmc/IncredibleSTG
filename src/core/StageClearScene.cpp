#include "StageClearScene.h"

namespace STG {

    StageClearScene::StageClearScene(int score):score(score){
        exit=false;
    }

    void StageClearScene::paint(QPainter* painter){
        QFont f;
        f.setBold(true);
        f.setPointSize(36);
        painter->setFont(f);
        painter->drawText(QPoint(400,400),"Stage Clear!");
        f.setPointSize(14);
        painter->setFont(f);
        if(~score)
            painter->drawText(QPoint(430,450),"Score : "+QString::number(score));
        painter->drawText(QPoint(430,490),"Press Esc to exit");

    }
    void StageClearScene::keyPress(int key){
        switch(key) {
        case Qt::Key_Escape:
            exit=true;
            break;
        default:
            break;
        }
    }
    void StageClearScene::keyRelease(int key){}

    BaseScene::GameResult StageClearScene::update(int milliInterval){
        if(exit) return BaseScene::MainMenu;
        return BaseScene::Gaming;
    }

}
