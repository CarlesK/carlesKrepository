#include "annuairegui.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnnuaireGUI w;
    //La ligne suivante permet de supporter les accents français dans Qt.
    //Tiré du post de Justin Hogue sur le forum du cours
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    w.show();
    return a.exec();
}
