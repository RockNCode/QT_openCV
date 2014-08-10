#-------------------------------------------------
#
# Project created by QtCreator 2014-08-10T00:20:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    effects.cpp

HEADERS  += mainwindow.h \
    other_effects.h \
    effects.h

FORMS    += mainwindow.ui
LIBS += -L/home/mgarcia/workspace/opencv-2.4.9/bin/
LIBS += -L/home/mgarcia/workspace/opencv-2.4.9/lib/ -lopencv_core -lopencv_highgui -lopencv_imgproc
