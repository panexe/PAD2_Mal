#-------------------------------------------------
#
# Project created by QtCreator 2019-05-04T17:44:47
#
#-------------------------------------------------

QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PAD2_Praktikum3_lars
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        algorithmen.cpp \
        booking.cpp \
        customer.cpp \
        flightbooking.cpp \
        heap.cpp \
        hotelbooking.cpp \
        main.cpp \
        mainwindow.cpp \
        newbookingdialog.cpp \
        rentalcarreservation.cpp \
        tablemodel.cpp \
        tablemodel_travel.cpp \
        test.cpp \
        travel.cpp \
        travelagency.cpp \
        traveldialog.cpp

HEADERS += \
        booking.h \
        customer.h \
        graph.h \
        flightbooking.h \
        hotelbooking.h \
        heap.h \
        mainwindow.h \
        newbookingdialog.h \
        rentalcarreservation.h \
        tablemodel.h \
        node.h \
        linkedlist.h \
        tablemodel_travel.h \
        test.h \
        travel.h \
        travelagency.h \
        traveldialog.h

FORMS += \
        mainwindow.ui \
        newbookingdialog.ui \
        traveldialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
