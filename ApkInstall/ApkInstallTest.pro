QT       += core gui

TARGET = DtuanduiTool
TEMPLATE = app
ICON = Image/logo128.icns

#DEFINES += QT_NO_DEBUG_OUTPUT
#CONFIG += console
SOURCES += main.cpp\
        widget.cpp \
    ibutton.cpp \
    labpermission.cpp \
    installthread.cpp \
    getapkinfothread.cpp \
    cmstring.cpp \
    elidedlabel.cpp

HEADERS  += widget.h \
    ibutton.h \
    labpermission.h \
    installthread.h \
    getapkinfothread.h \
    cmstring.h \
    elidedlabel.h

RC_FILE += apklogo.rc

RESOURCES += \
    img.qrc
