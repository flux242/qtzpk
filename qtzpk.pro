#-------------------------------------------------
#
# Project created by QtCreator 2013-07-06T16:52:03
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtzpk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    zpkutils.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    zpkutils.h

FORMS    += mainwindow.ui

RESOURCES += \
    core-profile.qrc

OTHER_FILES += \
    simple.vert \
    simple.frag
