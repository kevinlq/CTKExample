include($$PWD/../../CTKExample.pri)
include($$PWD/../../CTKExample_SupportLib.pri)

QT +=core gui widgets

TARGET = CTKExample
TEMPLATE = app

CONFIG += c++11

SOURCES += \
        Widget.cpp \
        main.cpp

HEADERS += \
    Widget.h


DIR_DEPEND_CTK_DEST = $${DESTDIR}

LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKCore
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKPluginFramework
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKWidgets

