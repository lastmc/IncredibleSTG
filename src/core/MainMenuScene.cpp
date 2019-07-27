#include "MainMenuScene.h"

namespace STG {

    MainMenuScene::MainMenuScene(){}

    void MainMenuScene::paint(QPainter* painter){
        QFont f;
        f.setBold(true);
        f.setPointSize(36);
        painter->setFont(f);
        painter->drawText(QPoint(200,200),"Shooting Game");
        f.setPointSize(14);
        painter->setFont(f);
        painter->drawText(QPoint(730,570),(select==MainMenuScene::StartGame)?"-> Start Game":"   Start Game");
        painter->drawText(QPoint(730,590),(select==MainMenuScene::ExitGame)?"-> Exit Game":"   Exit Game");
    }

    void MainMenuScene::keyPress(int key){
        switch(key){
        case Qt::Key_Up:
            select--;
            select+=MainMenuScene::End;
            break;
        case Qt::Key_Down:
            select++;
            break;
        case Qt::Key_Return://大键盘回车
        case Qt::Key_Enter://小键盘回车
            enter=true;
            break;
        default:
            break;
        }
        select%=MainMenuScene::End;
    }

    void MainMenuScene::keyRelease(int key){}

    BaseScene::GameResult MainMenuScene::update(int milliInterval){
        if(enter)
            switch(select){
            case MainMenuScene::StartGame:
                return BaseScene::GameStart;
            case MainMenuScene::ExitGame:
                return BaseScene::ExitGame;
            default:
                break;
            }
        return BaseScene::Gaming;
    }

}

