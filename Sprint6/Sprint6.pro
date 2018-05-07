TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    porter2_stemmer.cpp \
    tests.cpp \
    MemoryMapped.cpp \
    IndexHandler.cpp \
    FileProcessor.cpp \
    AVLTreeIndex.cpp \
    HashTableIndex.cpp \
    Word.cpp \
    QueryProcessor.cpp


HEADERS += \
    AVLTree.h \
    porter2_stemmer.h \
    catch.hpp \
    MemoryMapped.h \
    IndexHandler.h \
    FileProcessor.h \
    AVLTreeIndex.h \
    HashTable.h \
    HashTableIndex.h \
    IndexInterface.h \
    Word.h \
    QueryProcessor.h


