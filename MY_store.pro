#-------------------------------------------------
#
# Project created by QtCreator 2015-07-12T18:25:49
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MY_store
TEMPLATE = app


SOURCES += main.cpp\
        storekeeper.cpp \
    login.cpp \
    admin.cpp \
    user.cpp \
    credit.cpp \
    addgoods.cpp \
    display.cpp \
    update.cpp \
    changedialog.cpp \
    adduser.cpp \
    addnew.cpp \
    sales.cpp

HEADERS  += storekeeper.h \
    login.h \
    admin.h \
    user.h \
    credit.h \
    addgoods.h \
    display.h \
    update.h \
    changedialog.h \
    adduser.h \
    addnew.h \
    sales.h

FORMS    += storekeeper.ui \
    login.ui \
    admin.ui \
    user.ui \
    credit.ui \
    addgoods.ui \
    display.ui \
    update.ui \
    changedialog.ui \
    adduser.ui \
    addnew.ui \
    sales.ui
