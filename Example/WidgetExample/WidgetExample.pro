QT +=core gui widgets

TARGET = CTKExample
TEMPLATE = app

CONFIG += c++11

CONFIG(debug, debug|release):{
        FILE_POSTFIX = D
        DIR_COMPILEMODE = Debug
}
else:CONFIG(release, debug|release):{
        FILE_POSTFIX =
        DIR_COMPILEMODE = Release
}

CTK_DIR=$$PWD/../CTK

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH +=$${CTK_DIR}/include/ctk-0.1

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp


LIBS +=-L$${CTK_DIR}/lib/$${DIR_COMPILEMODE}/ctk-0.1 -lCTKCore
LIBS +=-L$${CTK_DIR}/lib/$${DIR_COMPILEMODE}/ctk-0.1 -lCTKPluginFramework
LIBS +=-L$${CTK_DIR}/lib/$${DIR_COMPILEMODE}/ctk-0.1 -lCTKWidgets
