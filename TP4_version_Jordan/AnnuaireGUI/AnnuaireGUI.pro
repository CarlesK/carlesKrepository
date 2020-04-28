TEMPLATE = app
TARGET = AnnuaireGUI
QT += core \
    gui
HEADERS += ajoutentraineurinterface.h \
    ajoutannuaireinterface.h \
    ajoutjoueurinterface.h \
    annuairegui.h
SOURCES += ajoutentraineurinterface.cpp \
    ajoutannuaireinterface.cpp \
    ajoutjoueurinterface.cpp \
    main.cpp \
    annuairegui.cpp
FORMS += ajoutentraineurinterface.ui \
    ajoutannuaireinterface.ui \
    ajoutjoueurinterface.ui \
    annuairegui.ui
RESOURCES += 
LIBS += "../Source/Debug/libSource.a"
INCLUDEPATH += "../Source/."
