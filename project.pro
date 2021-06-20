QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add.cpp \
    dialog.cpp \
    edit.cpp \
    forget.cpp \
    home.cpp \
    main.cpp \
    reserve.cpp \
    signup.cpp

HEADERS += \
    add.h \
    classes.h \
    dialog.h \
    edit.h \
    forget.h \
    home.h \
    reserve.h \
    signup.h

FORMS += \
    add.ui \
    dialog.ui \
    edit.ui \
    forget.ui \
    home.ui \
    reserve.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    icons.qrc
