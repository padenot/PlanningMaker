#-------------------------------------------------
#
# Project created by QtCreator 2010-12-05T15:22:26
#
#-------------------------------------------------
include(QxOrm.pri)
QT       += core gui sql

TARGET = PlanningMaker
TEMPLATE = app
PRECOMPILED_HEADER = ./include/precompiled.h
INCLUDEPATH += ./QxOrm/include/


CONFIG(debug, debug|release) {
DESTDIR = ./build/debug
LIBS += -l"QxOrmd"
} else {

LIBS += -l"QxOrm"
DESTDIR = ./build/release
}






SOURCES +=  ./src/main.cpp\
            ./src/mainwindow.cpp \
    ./src/orga.cpp \
./src/departement.cpp \
./src/equipe.cpp \
./src/categorie.cpp \
./src/tache.cpp \
./src/groupetaches.cpp \
./src/lieu.cpp \
./src/materiel.cpp \
    src/planningmodel.cpp \
    src/orgaeditwidget.cpp \
    src/orgaselectwidget.cpp \
src/manifeditwidget.cpp \
src/cateditwidget.cpp


HEADERS  += ./include/mainwindow.h \
            ./include/precompiled.h \
            ./include/export.h \
    ./include/orga.h \
./include/departement.h \
./include/equipe.h \
./include/categorie.h \
./include/tache.h \
./include/groupetaches.h \
./include/lieu.h \
./include/materiel.h \
    include/planningmodel.h \
    include/orgaeditwidget.h \
    include/orgaselectwidget.h \
include/manifeditwidget.h \
include/cateditwidget.h

FORMS    += ./ui/mainwindow.ui \
    ./ui/orgalistdialog.ui \
    ui/orgaCentral.ui \
    ui/orgaeditwidget.ui \
    ui/orgaselectwidget.ui \
ui/manifeditwidget.ui \
ui/cateditwidget.ui

RESOURCES += \
    images.qrc
