include($$PWD/../CTKPluginExample.pri)
include($$PWD/../../../CTKExample_SupportLib.pri)

QT +=core

TARGET = WelcomeQt

TEMPLATE = lib

CONFIG += c++11

SOURCES += \
    WelcomeService.cpp \
    WelcomeQtImpl.cpp \
    WelcomeQtActivator.cpp

HEADERS += \
    WelcomeService.h \
    WelcomeQtImpl.h \
    WelcomeQtActivator.h

RESOURCES += \
    resource.qrc

LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKCore
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKPluginFramework
#LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKWidgets


