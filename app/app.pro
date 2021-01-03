QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Entities/address.cpp \
    Entities/customer.cpp \
    Entities/pool.cpp \
    ReservationManagers/basereservationmanager.cpp \
    ReservationManagers/poolreservationmanager.cpp \
    Reservations/basereservation.cpp \
    Reservations/poolreservation.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Entities/address.h \
    Entities/customer.h \
    Entities/pool.h \
    ReservationManagers/basereservationmanager.h \
    ReservationManagers/poolreservationmanager.h \
    Reservations/basereservation.h \
    Reservations/poolreservation.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
