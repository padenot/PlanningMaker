#-------------------------------------------------
#
# Project created by QtCreator 2010-12-05T15:22:26
#
#-------------------------------------------------
include(QxOrm.pri)
QT       += core gui

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
    ./src/orgalistdialog.cpp \
./src/departement.cpp \
./src/equipe.cpp \
./src/categorie.cpp \
./src/tache.cpp \
./src/groupetaches.cpp \
./src/lieu.cpp \
./src/materiel.cpp


HEADERS  += ./include/mainwindow.h \
            ./include/precompiled.h \
            ./include/export.h \
    ./include/orga.h \
    ./include/orgalistdialog.h\
./include/departement.h \
./include/equipe.h \
./include/categorie.h \
./include/tache.h \
./include/groupetaches.h \
./include/lieu.h \
./include/materiel.h

FORMS    += ./ui/mainwindow.ui \
    ./ui/orgalistdialog.ui
