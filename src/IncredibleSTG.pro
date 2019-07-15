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
    core/BaseBullet.cpp \
    core/BaseObject.cpp \
    core/BaseScene.cpp \
    core/DirectionBullet.cpp \
    core/GameScene.cpp \
    core/HeroObject.cpp \
        gui/gamewidget.cpp \
        main.cpp \

HEADERS += \
    core/BaseBullet.h \
    core/BaseObject.h \
    core/BaseScene.h \
    core/DirectionBullet.h \
    core/GameScene.h \
    core/HeroObject.h \
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
