#include "gamewidget.h"
#include "ui_gamewidget.h"
#include <QPainter>
#include <QKeyEvent>


#include "../core/GameScene.h"
#include "../core/GameOverScene.h"

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

    STG::GameScene* gScene=new STG::GameScene();
    scene=gScene;
    timer.setTimerType(Qt::PreciseTimer);
    timer.setInterval(10);
    connect(&timer,SIGNAL(timeout()),this,SLOT(repaint()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(updateScene()));
    timer.start();

}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::updateScene(){
    switch(scene->update(10)){
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
