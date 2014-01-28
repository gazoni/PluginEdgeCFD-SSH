# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = app
TARGET = runEdgeCFD
DESTDIR = ./bin
QT += core gui xml opengl
CONFIG += debug
DEFINES += QT_LARGEFILE_SUPPORT QT_DLL QT_XML_LIB QT_OPENGL_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
LIBS += -lopengl32 \
    -lglu32
#PRECOMPILED_HEADER = StdAfx.h
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./formOrdenado.h \
    ./forms.h \
    ./resource.h \
    ./resource1.h \
    ./runedgecfd.h \
    ./io.h \
    configansys.h
SOURCES += ./io.cpp \
    ./main.cpp \
    ./runedgecfd.cpp \
    configansys.cpp
FORMS += ./runedgecfd.ui \
    ./menuAnsys.ui \
    configansys.ui
RESOURCES += runedgecfd.qrc
