QT += core
QT += network
QT -= gui

TARGET = WebServer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    httpserver.cpp \
    httpworker.cpp \
    httpheaderhandler.cpp

HEADERS += \
    httpserver.h \
    httpworker.h \
    httpheaderhandler.h

