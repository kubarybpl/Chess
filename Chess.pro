QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    chessboard.cpp \
    chessbox.cpp \
    gamescene.cpp \
    main.cpp \
    mainwindow.cpp \
    menuScene.cpp \
    pawn.cpp \
    piece.cpp \
    sceneView.cpp \
    settingsscene.cpp

HEADERS += \
    button.h \
    chessboard.h \
    chessbox.h \
    gamescene.h \
    mainwindow.h \
    menuScene.h \
    pawn.h \
    piece.h \
    sceneView.h \
    settingsscene.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pieces.qrc
