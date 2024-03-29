#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QPainter>
#include <QKeyEvent>

#include "../core/MainMenuScene.h"
#include "../core/GameScene.h"
#include "../core/GameOverScene.h"
#include "../core/StageClearScene.h"
#include "../core/ReplayScene.h"
#include "../core/AIScene.h"

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    //Initialization
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    buffPixMap=QPixmap(this->width(),this->height());
    buffPixMap.fill(Qt::white);
    buffPainter.begin(&buffPixMap);

    scene=new STG::MainMenuScene();
    timer.setTimerType(Qt::PreciseTimer);
    timer.setInterval(10);
    connect(&timer,SIGNAL(timeout()),this,SLOT(repaint()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateScene()));
    timer.start();

}

GameWidget::~GameWidget()
{
    delete ui;
    if(scene) delete scene;
}

void GameWidget::updateScene(){
    switch(scene->update(10)){
    case STG::BaseScene::Replay:
        delete scene;
        scene=new STG::ReplayScene();
        break;
    case STG::BaseScene::AIStart:
        delete scene;
        scene=new STG::AIScene();
        break;
    case STG::BaseScene::GameStart:
    case STG::BaseScene::Retry:
        delete scene;
        scene=new STG::GameScene();
        break;
    case STG::BaseScene::GameOver:{
        STG::GameScene* ptr=dynamic_cast<STG::GameScene*>(scene);
        int score=-1;
        if(ptr) score=ptr->getScore();
        delete scene;
        scene=new STG::GameOverScene(score);
        break;
    }
    case STG::BaseScene::StageClear:{
        STG::GameScene* ptr=dynamic_cast<STG::GameScene*>(scene);
        int score=-1;
        if(ptr) score=ptr->getScore();
        delete scene;
        scene=new STG::StageClearScene(score);
        break;
    }
    case STG::BaseScene::MainMenu:
        delete scene;
        scene=new STG::MainMenuScene();
        break;
    case STG::BaseScene::ExitGame:
        exit(0);
    default:
        break;
    }
}

void GameWidget::paintEvent(QPaintEvent*){
    buffPixMap.fill(Qt::white);
    if(scene) scene->paint(&buffPainter);
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),buffPixMap);
}

void GameWidget::keyPressEvent(QKeyEvent *event){
    scene->keyPress(event->key());
}

void GameWidget::keyReleaseEvent(QKeyEvent *event){
    scene->keyRelease(event->key());
}
