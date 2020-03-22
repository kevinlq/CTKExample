include($$PWD/../CTKPluginExample.pri)
include($$PWD/../../../CTKExample_SupportLib.pri)

QT +=core

TARGET = LogPlugin
TEMPLATE = lib

CONFIG += c++11


HEADERS += \
    LogQDebug.h \
    LoginPlugin.h

SOURCES += \
    LogQDebug.cpp \
    LoginPlugin.cpp

RESOURCES += \
    resource.qrc



LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKCore
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKPluginFramework
