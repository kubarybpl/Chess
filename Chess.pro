QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bishop.cpp \
    button.cpp \
    chessboard.cpp \
    chessbox.cpp \
    gamescene.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    mainwindow.cpp \
    menuScene.cpp \
    pawn.cpp \
    piece.cpp \
    queen.cpp \
    rook.cpp \
    sceneView.cpp \
    settingsscene.cpp

HEADERS += \
    bishop.h \
    button.h \
    chessboard.h \
    chessbox.h \
    chessenum.h \
    gamescene.h \
    king.h \
    knight.h \
    mainwindow.h \
    menuScene.h \
    pawn.h \
    piece.h \
    queen.h \
    rook.h \
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
