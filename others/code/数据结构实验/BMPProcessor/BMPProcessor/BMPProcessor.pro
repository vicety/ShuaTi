#-------------------------------------------------
#
# Project created by QtCreator 2017-12-13T12:33:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BMPProcessor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    pixmap.cpp

HEADERS  += mainwindow.h \
    pixmap.h

FORMS    += mainwindow.ui

RESOURCES += \
    qss/qss.qrc

DISTFILES += \
    qss/psblack/add_bottom.png \
    qss/psblack/add_left.png \
    qss/psblack/add_right.png \
    qss/psblack/add_top.png \
    qss/psblack/branch_close.png \
    qss/psblack/branch_open.png \
    qss/psblack/calendar_nextmonth.png \
    qss/psblack/calendar_prevmonth.png \
    qss/psblack/checkbox_checked.png \
    qss/psblack/checkbox_checked_disable.png \
    qss/psblack/checkbox_parcial.png \
    qss/psblack/checkbox_parcial_disable.png \
    qss/psblack/checkbox_unchecked.png \
    qss/psblack/checkbox_unchecked_disable.png \
    qss/psblack/radiobutton_checked.png \
    qss/psblack/radiobutton_checked_disable.png \
    qss/psblack/radiobutton_unchecked.png \
    qss/psblack/radiobutton_unchecked_disable.png \
    qss/lightgrey.css \
    qss/psblack.css
