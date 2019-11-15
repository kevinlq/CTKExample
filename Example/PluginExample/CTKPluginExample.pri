# Config Para
CONFIG +=MinGW

CONFIG(debug, debug|release):{
        FILE_POSTFIX = D
        DIR_COMPILEMODE = Debug
}
else:CONFIG(release, debug|release):{
        FILE_POSTFIX =
        DIR_COMPILEMODE = Release
}

win32:{
    CONFIG(MinGW, MinGW|MinGW64):{
        DIR_PLATFORM = Win32
        }
    else:CONFIG(MinGW64, MinGW|MinGW64):{
        DIR_PLATFORM = Win64
    }
}
else:android:{
        DIR_PLATFORM = Android
}
else:ios:{
        DEFINES += IOS
        DIR_PLATFORM = IOS
}
else:mac:{
        DEFINES += MAC
        DIR_PLATFORM = MAC
}
else:linux:{
        DIR_PLATFORM = Linux
}

DESTDIR  = $$PWD/../../Bin/$${DIR_PLATFORM}/$${DIR_COMPILEMODE}/plugins
