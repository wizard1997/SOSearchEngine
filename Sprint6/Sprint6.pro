TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fileparser.cpp \
    porter2_stemmer.cpp \
    word.cpp

HEADERS += \
    AVLTree.h \
    fileparser.h \
    porter2_stemmer.h \
    word.h
