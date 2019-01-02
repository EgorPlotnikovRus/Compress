TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    compress.cpp \
    decompress.cpp

HEADERS += \
    compress.h \
    head.h \
    decompress.h
