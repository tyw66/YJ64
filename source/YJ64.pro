############################################################
## 可视化：易经六十四卦
## 2023.4.16
############################################################

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    database.h \
    diagram.h \
    mainwindow.h \
    yao.h


SOURCES += \
    database.cpp \
    diagram.cpp \
    main.cpp \
    mainwindow.cpp \
    yao.cpp

FORMS += \
    mainwindow.ui

RESOURCES += \
    res.qrc

TRANSLATIONS+=\
    zh_CN.ts
