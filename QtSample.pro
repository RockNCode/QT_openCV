#-------------------------------------------------
#
# Project created by QtCreator 2014-08-10T00:20:34
#
#-------------------------------------------------

MYWINOPENCVPATH = C:/Users/manuel.gar/workspace/opencv
MYLINUXOPENCVPATH = /home/mgarcia/workspace/opencv-2.4.9

QT       += core gui widgets

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

unix: LIBS += -L$$MYLINUXOPENCVPATH/lib/ -lopencv_core -lopencv_highgui -lopencv_imgproc
win32:LIBS += -L$$MYWINOPENCVPATH/build/x64/vc12/lib -lopencv_core249d -lopencv_highgui249d -lopencv_imgproc249d
win32:INCLUDEPATH += $$MYWINOPENCVPATH/build/include
