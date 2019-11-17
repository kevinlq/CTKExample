include($$PWD/../CTKPluginExample.pri)
include($$PWD/../../../CTKExample_SupportLib.pri)

QT +=core

TARGET = WelcomeCTK
TEMPLATE = lib

CONFIG += c++11

SOURCES += \
    WelcomeService.cpp \
    WelcomeCTKImpl.cpp \
    WelcomeCTKActivator.cpp

HEADERS += \
    WelcomeService.h \
    WelcomeCTKImpl.h \
    WelcomeCTKActivator.h

RESOURCES += \
    resource.qrc

LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKCore
LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKPluginFramework
#LIBS +=-L$${DIR_DEPEND_CTK_DEST}/ -lCTKWidgets


