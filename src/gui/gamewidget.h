#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QTimer>
#include "../core/BaseScene.h"
#include "../core/GameScene.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget() override;

    void paintEvent(QPaintEvent*) Q_DECL_OVERRIDE;
    void keyPressEvent(QKeyEvent* event) Q_DECL_OVERRIDE;
    void keyReleaseEvent(QKeyEvent* event) Q_DECL_OVERRIDE;
public slots:
    void updateScene();
private:
    Ui::GameWidget *ui;
    STG::BaseScene* scene;
    QPixmap buffPixMap;
    QPainter buffPainter;
    QTimer timer;

};

#endif // GAMEWIDGET_H
