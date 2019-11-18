include($$PWD/../CTKPluginExample.pri)
include($$PWD/../../../CTKExample_SupportLib.pri)

QT +=core

TARGET = BlogManager
TEMPLATE = lib

CONFIG += c++11


HEADERS += \
    BlogManager.h \
    BlogManagerActivator.h

SOURCES += \
    BlogManager.cpp \
    BlogManagerActivator.cpp


RESOURCES += \
    resource.qrc

LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKCore
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKPluginFramework
#LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKWidgets


