QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Entities/address.cpp \
    Entities/customer.cpp \
    Entities/pool.cpp \
    GeneralManagers/addressmanager.cpp \
    GeneralManagers/customermanager.cpp \
    ReservationManagers/poolreservationmanager.cpp \
    Reservations/basereservation.cpp \
    Reservations/poolreservation.cpp \
    home.cpp \
    main.cpp \
    mainwindow.cpp \
    table.cpp

HEADERS += \
    Entities/address.h \
    Entities/customer.h \
    Entities/pool.h \
    GeneralManagers/addressmanager.h \
    GeneralManagers/customermanager.h \
    ReservationManagers/poolreservationmanager.h \
    Reservations/basereservation.h \
    Reservations/poolreservation.h \
    connection.h \
    home.h \
    mainwindow.h \
    table.h

FORMS += \
    home.ui \
    mainwindow.ui \
    table.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
