#-------------------------------------------------
#
# Project created by QtCreator 2015-12-20T14:10:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = wifiSux
TEMPLATE = app
CONFIG+=c++11

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -pedantic

SOURCES += main.cpp\
        mainwindow.cpp \
    networkpinger.cpp

HEADERS  += mainwindow.h \
    networkpinger.h

FORMS    += mainwindow.ui
