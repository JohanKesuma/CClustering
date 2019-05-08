#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T16:52:20
#
#-------------------------------------------------

QT       += widgets

TARGET = Clustering
TEMPLATE = lib

DEFINES += CLUSTERING_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clusterdialogs/kmeandialog.cpp \
    clusterdialogs/kmeanresultdialog.cpp \
    clusterwidgets/kmeanwidget.cpp \
    data.cpp \
    kmeans.cpp

HEADERS += \
        clusterdialogs/kmeandialog.h \
        clusterdialogs/kmeanresultdialog.h \
        clustering_global.h  \
        clusterwidgets/kmeanwidget.h \
        data.h \
        kmeans.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += $$PWD/../../../include/

FORMS += \
    clusterdialogs/kmeanresultdialog.ui \
    clusterwidgets/kmeanwidget.ui \
    kmeandialog.ui


