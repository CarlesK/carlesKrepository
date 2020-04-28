/********************************************************************************
** Form generated from reading UI file 'annuairegui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANNUAIREGUI_H
#define UI_ANNUAIREGUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnnuaireGUIClass
{
public:
    QAction *actionAjouter_Joueur;
    QAction *actionQuitter;
    QAction *actionJoueur;
    QAction *actionEntraineur;
    QAction *actionEntrerNomEquipe;
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEditInfoEquipe;
    QSpacerItem *horizontalSpacer_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuAjouter_Personne;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AnnuaireGUIClass)
    {
        if (AnnuaireGUIClass->objectName().isEmpty())
            AnnuaireGUIClass->setObjectName(QString::fromUtf8("AnnuaireGUIClass"));
        AnnuaireGUIClass->resize(800, 600);
        actionAjouter_Joueur = new QAction(AnnuaireGUIClass);
        actionAjouter_Joueur->setObjectName(QString::fromUtf8("actionAjouter_Joueur"));
        actionQuitter = new QAction(AnnuaireGUIClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionJoueur = new QAction(AnnuaireGUIClass);
        actionJoueur->setObjectName(QString::fromUtf8("actionJoueur"));
        actionEntraineur = new QAction(AnnuaireGUIClass);
        actionEntraineur->setObjectName(QString::fromUtf8("actionEntraineur"));
        actionEntrerNomEquipe = new QAction(AnnuaireGUIClass);
        actionEntrerNomEquipe->setObjectName(QString::fromUtf8("actionEntrerNomEquipe"));
        centralwidget = new QWidget(AnnuaireGUIClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 130, 801, 371));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        textEditInfoEquipe = new QTextEdit(horizontalLayoutWidget);
        textEditInfoEquipe->setObjectName(QString::fromUtf8("textEditInfoEquipe"));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier 10 Pitch"));
        textEditInfoEquipe->setFont(font);
        textEditInfoEquipe->setReadOnly(true);

        horizontalLayout->addWidget(textEditInfoEquipe);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, -1, 801, 131));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_3 = new QSpacerItem(100, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        AnnuaireGUIClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AnnuaireGUIClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuAjouter_Personne = new QMenu(menuMenu);
        menuAjouter_Personne->setObjectName(QString::fromUtf8("menuAjouter_Personne"));
        AnnuaireGUIClass->setMenuBar(menubar);
        statusbar = new QStatusBar(AnnuaireGUIClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AnnuaireGUIClass->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionEntrerNomEquipe);
        menuMenu->addAction(menuAjouter_Personne->menuAction());
        menuMenu->addAction(actionQuitter);
        menuAjouter_Personne->addAction(actionJoueur);
        menuAjouter_Personne->addAction(actionEntraineur);

        retranslateUi(AnnuaireGUIClass);
        QObject::connect(actionQuitter, SIGNAL(triggered()), AnnuaireGUIClass, SLOT(close()));

        QMetaObject::connectSlotsByName(AnnuaireGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *AnnuaireGUIClass)
    {
        AnnuaireGUIClass->setWindowTitle(QApplication::translate("AnnuaireGUIClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAjouter_Joueur->setText(QApplication::translate("AnnuaireGUIClass", "Ajouter Joueur", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("AnnuaireGUIClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionJoueur->setText(QApplication::translate("AnnuaireGUIClass", "Joueur", 0, QApplication::UnicodeUTF8));
        actionEntraineur->setText(QApplication::translate("AnnuaireGUIClass", "Entraineur", 0, QApplication::UnicodeUTF8));
        actionEntrerNomEquipe->setText(QApplication::translate("AnnuaireGUIClass", "Entrer nom d'\303\251quipe", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AnnuaireGUIClass", "INFOS DE L'\303\211QUIPE", 0, QApplication::UnicodeUTF8));
        menuMenu->setTitle(QApplication::translate("AnnuaireGUIClass", "Menu", 0, QApplication::UnicodeUTF8));
        menuAjouter_Personne->setTitle(QApplication::translate("AnnuaireGUIClass", "Ajouter Personne ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AnnuaireGUIClass: public Ui_AnnuaireGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANNUAIREGUI_H
