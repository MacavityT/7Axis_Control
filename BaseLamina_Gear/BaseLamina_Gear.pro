#-------------------------------------------------
#
# Project created by QtCreator 2018-01-10T09:31:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaseLamina_Gear
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    paramdialog.cpp \
    initialization.cpp \
    sensorthread.cpp \
    commidialog.cpp \
    io_control.cpp \
    actionprocess.cpp \
    actionthread1.cpp \
    actionthread2.cpp \
    actionthread3.cpp \
    buttonthread.cpp \
    risedgethread.cpp

HEADERS += \
        mainwindow.h \
    paramdialog.h \
    LTDMC.h \
    sensorthread.h \
    commidialog.h \
    actionprocess.h \
    actionthread1.h \
    actionthread2.h \
    actionthread3.h \
    buttonthread.h \
    risedgethread.h

FORMS += \
        mainwindow.ui \
    paramdialog.ui \
    commissioning.ui


#DLLDESTDIR +=..\LTDMC.dll
#DLLDESTDIR+=.\
#CONFIG+=c++11

win32: LIBS += -L$$PWD/./ -lLTDMC

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

