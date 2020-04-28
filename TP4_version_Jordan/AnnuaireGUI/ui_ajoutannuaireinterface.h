/********************************************************************************
** Form generated from reading UI file 'ajoutannuaireinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTANNUAIREINTERFACE_H
#define UI_AJOUTANNUAIREINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutAnnuaireInterfaceClass
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEditNomEquipe;
    QLabel *label_validationNomEquipe;
    QPushButton *pushButtonNomEquipe;

    void setupUi(QDialog *AjoutAnnuaireInterfaceClass)
    {
        if (AjoutAnnuaireInterfaceClass->objectName().isEmpty())
            AjoutAnnuaireInterfaceClass->setObjectName(QString::fromUtf8("AjoutAnnuaireInterfaceClass"));
        AjoutAnnuaireInterfaceClass->resize(518, 311);
        horizontalLayoutWidget = new QWidget(AjoutAnnuaireInterfaceClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 521, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        formLayoutWidget = new QWidget(AjoutAnnuaireInterfaceClass);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(80, 150, 361, 63));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEditNomEquipe = new QLineEdit(formLayoutWidget);
        lineEditNomEquipe->setObjectName(QString::fromUtf8("lineEditNomEquipe"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNomEquipe);

        label_validationNomEquipe = new QLabel(formLayoutWidget);
        label_validationNomEquipe->setObjectName(QString::fromUtf8("label_validationNomEquipe"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_validationNomEquipe);

        pushButtonNomEquipe = new QPushButton(formLayoutWidget);
        pushButtonNomEquipe->setObjectName(QString::fromUtf8("pushButtonNomEquipe"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButtonNomEquipe);


        retranslateUi(AjoutAnnuaireInterfaceClass);
        QObject::connect(pushButtonNomEquipe, SIGNAL(clicked()), AjoutAnnuaireInterfaceClass, SLOT(validerEnregistrement()));

        QMetaObject::connectSlotsByName(AjoutAnnuaireInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutAnnuaireInterfaceClass)
    {
        AjoutAnnuaireInterfaceClass->setWindowTitle(QApplication::translate("AjoutAnnuaireInterfaceClass", "AjoutAnnuaireInterface", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AjoutAnnuaireInterfaceClass", "Ajouter nom d'\303\251quipe", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AjoutAnnuaireInterfaceClass", "Nom d'\303\251quipe", 0, QApplication::UnicodeUTF8));
        label_validationNomEquipe->setText(QApplication::translate("AjoutAnnuaireInterfaceClass", "Validation", 0, QApplication::UnicodeUTF8));
        pushButtonNomEquipe->setText(QApplication::translate("AjoutAnnuaireInterfaceClass", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjoutAnnuaireInterfaceClass: public Ui_AjoutAnnuaireInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTANNUAIREINTERFACE_H
