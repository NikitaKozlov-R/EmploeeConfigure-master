QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    productinformation.cpp \
    productscrollarea.cpp \
    productwidget.cpp \
    stockpileinformation.cpp \
    stockpilescrollarea.cpp \
    stockpilewidget.cpp \
    workerscrollarea.cpp \
    workerswidget.cpp

HEADERS += \
    mainwindow.h \
    productinformation.h \
    productscrollarea.h \
    productwidget.h \
    stockpileinformation.h \
    stockpilescrollarea.h \
    stockpilewidget.h \
    workerscrollarea.h \
    workerswidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
