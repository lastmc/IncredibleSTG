#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
}

GameWidget::~GameWidget()
{
    delete ui;
}
