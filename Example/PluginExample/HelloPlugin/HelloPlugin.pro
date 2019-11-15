include($$PWD/../CTKPluginExample.pri)
include($$PWD/../../../CTKExample_SupportLib.pri)

QT +=core

TARGET = HelloPlugin
TEMPLATE = lib

CONFIG += c++11

SOURCES += \
        HelloActivator.cpp \
        HelloImpl.cpp \
        HelloServer.cpp

HEADERS += \
    HelloActivator.h \
    HelloImpl.h \
    HelloServer.h

RESOURCES += \
    resource.qrc

LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKCore
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKPluginFramework
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKWidgets


