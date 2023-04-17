############################################################
## 可视化：易经六十四卦
## 2023.4.16
############################################################

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    graphicsitemyao.h \
    mainwindow.h \

SOURCES += \
    graphicsitemyao.cpp \
    main.cpp \
    mainwindow.cpp \

FORMS += \
    mainwindow.ui

RESOURCES += \
    res.qrc



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
