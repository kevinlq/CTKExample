include($$PWD/../CTKPluginExample.pri)
include($$PWD/../../../CTKExample_SupportLib.pri)

QT +=core

TARGET = BlogEventHandler
TEMPLATE = lib

CONFIG += c++11


HEADERS += \
    BlogEventHandler.h \
    BlogEventHandlerActivator.h

SOURCES += \
    BlogEventHandler.cpp \
    BlogEventHandlerActivator.cpp

RESOURCES += \
    resource.qrc

LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKCore
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKPluginFramework
#LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKWidgets



