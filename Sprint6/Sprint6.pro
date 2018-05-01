TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fileparser.cpp \
    porter2_stemmer.cpp \
    word.cpp \
    tests.cpp \
    queryprocessor.cpp \
    MemoryMapped.cpp \
    indexinterface.cpp \
    avltreeindex.cpp \
    hashtableindex.cpp


HEADERS += \
    AVLTree.h \
    fileparser.h \
    porter2_stemmer.h \
    word.h \
    catch.hpp \
    hashtable.h \
    queryprocessor.h \
    MemoryMapped.h \
    indexinterface.h \
    avltreeindex.h \
    hashtableindex.h
