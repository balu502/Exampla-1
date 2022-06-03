QT += core
QT -= gui

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    cbqcoreapplication.cpp

INCLUDEPATH += ../
INCLUDEPATH += ../../../qextserialport/src
HEADERS += ../conbarcode.h \
    cbqcoreapplication.h



CONFIG(debug,debug|release)DEBUG_SFX = d

win32-msvc* {COBUILD = VC
}else{       COBUILD = GC
}

RUNS_DIR = ../../../run$${COBUILD}$$QT_MAJOR_VERSION$$QT_MINOR_VERSION

LIBS += $${RUNS_DIR}/libconbarcode$${DEBUG_SFX}.so
TARGET = cabc
DESTDIR = $${RUNS_DIR}

