#-------------------------------------------------
#
# Project created by QtCreator 2014-08-28T12:43:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Splat
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    ../opcodeProcessing.cpp \
    ../stateData.cpp

HEADERS  += mainwindow.h \
    ../loadRom.h \
    ../opcodeProcessing.h \
    ../stateData.h

FORMS    += mainwindow.ui

LIBS += -lX11 -lGL
