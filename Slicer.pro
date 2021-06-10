QT       += \
    core gui \
    core5compat

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editor.cpp \
    main.cpp \
    mainwindow.cpp \
    questions.cpp \
    settings.cpp \
    test_wind.cpp \
    visual.cpp

HEADERS += \
    editor.h \
    mainwindow.h \
    questions.h \
    settings.h \
    test_wind.h \
    visual.h

FORMS += \
    editor.ui \
    mainwindow.ui \
    questions.ui \
    settings.ui \
    test_wind.ui \
    visual.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/Code New Roman.otf \
    resources/test.png

RESOURCES += \
    resources/res.qrc
