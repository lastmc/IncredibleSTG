#-------------------------------------------------
#
# Project created by QtCreator 2019-07-14T09:39:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IncredibleSTG
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    core/AIPlayer.cpp \
    core/AIScene.cpp \
    core/BaseEnemyObject.cpp \
    core/BaseMovement.cpp \
    core/BaseObject.cpp \
    core/BonusBullet.cpp \
    core/BossEnemy.cpp \
    core/BulletContainer.cpp \
    core/ButterflyEnemy.cpp \
    core/CircleBullet.cpp \
    core/CircleMovement.cpp \
    core/DirectionBullet.cpp \
    core/DirectionMovement.cpp \
    core/EnemyContainer.cpp \
    core/EnemyFactory.cpp \
    core/FairyEnemy.cpp \
    core/GameOverScene.cpp \
    core/GameScene.cpp \
    core/HeroObject.cpp \
    core/MainMenuScene.cpp \
    core/MovementContainer.cpp \
    core/Recorder.cpp \
    core/ReplayScene.cpp \
    core/StageClearScene.cpp \
    core/TestEnemy.cpp \
        gui/gamewidget.cpp \
        main.cpp \

HEADERS += \
    core/AIPlayer.h \
    core/AIScene.h \
    core/BaseBullet.h \
    core/BaseEnemyObject.h \
    core/BaseMovement.h \
    core/BaseObject.h \
    core/BaseScene.h \
    core/BonusBullet.h \
    core/BossEnemy.h \
    core/BulletContainer.h \
    core/ButterflyEnemy.h \
    core/CircleBullet.h \
    core/CircleMovement.h \
    core/DirectionBullet.h \
    core/DirectionMovement.h \
    core/EnemyContainer.h \
    core/EnemyFactory.h \
    core/FairyEnemy.h \
    core/GameOverScene.h \
    core/GameScene.h \
    core/HeroObject.h \
    core/MainMenuScene.h \
    core/MovementContainer.h \
    core/Recorder.h \
    core/ReplayScene.h \
    core/SceneInfo.h \
    core/StageClearScene.h \
    core/TestEnemy.h \
    core/ToolFunc.h \
    gui/gamewidget.h

FORMS += \
        gui/gamewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/resource.qrc
