include($$PWD/../../../CTKExample.pri)
include($$PWD/../../../CTKExample_SupportLib.pri)

QT +=core gui widgets

TARGET = EventAdmin
TEMPLATE = app

CONFIG += c++11
CONFIG  +=console

SOURCES += \
        main.cpp


DIR_DEPEND_CTK_DEST = $${DESTDIR}

LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKCore
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKPluginFramework
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKWidgets

