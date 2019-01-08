QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += QT_DEPRECATED_WARNINGS

TEMPLATE = app

SOURCES += main.cpp \
    compress.cpp \
    decompress.cpp \
    window.cpp

HEADERS += \
    compress.h \
    head.h \
    decompress.h \
    window.h
