#-------------------------------------------------
#
# Project created by QtCreator 2017-09-15T04:38:04
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
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
        sr.cpp \
    dbmanager.cpp \
    alert.cpp \
    uieditcourses.cpp \
    uiaddeditstudent.cpp

HEADERS += \
        sr.h \
    dbmanager.hpp \
    alert.hpp \
    uieditcourses.h \
    uiaddeditstudent.h

FORMS += \
        sr.ui \
    uieditcourses.ui \
    uiaddeditstudent.ui


CONFIG += c++14

DISTFILES += \
    README.md \
    StudentRecord.sql \
    StudentRecord.db

RC_ICONS = ico.ico
