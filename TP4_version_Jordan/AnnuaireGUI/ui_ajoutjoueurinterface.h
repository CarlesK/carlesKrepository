/********************************************************************************
** Form generated from reading UI file 'ajoutjoueurinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTJOUEURINTERFACE_H
#define UI_AJOUTJOUEURINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
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

class Ui_AjoutJoueurInterfaceClass
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelprenom;
    QLineEdit *prenomLineEdit;
    QLabel *labelNom;
    QLineEdit *nomLineEdit;
    QLabel *labelDateNaissance;
    QDateEdit *dateNaissanceDateEdit;
    QLabel *labelNumeroTelephone;
    QLineEdit *numeroTelephoneLineEdit;
    QLabel *labelPosition;
    QComboBox *positionComboBox;
    QLabel *labelVazlidation;
    QPushButton *validationPushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QLabel *labelEnteteInterfaceAjoutJoueur;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AjoutJoueurInterfaceClass)
    {
        if (AjoutJoueurInterfaceClass->objectName().isEmpty())
            AjoutJoueurInterfaceClass->setObjectName(QString::fromUtf8("AjoutJoueurInterfaceClass"));
        AjoutJoueurInterfaceClass->resize(489, 267);
        AjoutJoueurInterfaceClass->setSizeGripEnabled(false);
        formLayoutWidget = new QWidget(AjoutJoueurInterfaceClass);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 60, 471, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelprenom = new QLabel(formLayoutWidget);
        labelprenom->setObjectName(QString::fromUtf8("labelprenom"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelprenom);

        prenomLineEdit = new QLineEdit(formLayoutWidget);
        prenomLineEdit->setObjectName(QString::fromUtf8("prenomLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, prenomLineEdit);

        labelNom = new QLabel(formLayoutWidget);
        labelNom->setObjectName(QString::fromUtf8("labelNom"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNom);

        nomLineEdit = new QLineEdit(formLayoutWidget);
        nomLineEdit->setObjectName(QString::fromUtf8("nomLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nomLineEdit);

        labelDateNaissance = new QLabel(formLayoutWidget);
        labelDateNaissance->setObjectName(QString::fromUtf8("labelDateNaissance"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelDateNaissance);

        dateNaissanceDateEdit = new QDateEdit(formLayoutWidget);
        dateNaissanceDateEdit->setObjectName(QString::fromUtf8("dateNaissanceDateEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, dateNaissanceDateEdit);

        labelNumeroTelephone = new QLabel(formLayoutWidget);
        labelNumeroTelephone->setObjectName(QString::fromUtf8("labelNumeroTelephone"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelNumeroTelephone);

        numeroTelephoneLineEdit = new QLineEdit(formLayoutWidget);
        numeroTelephoneLineEdit->setObjectName(QString::fromUtf8("numeroTelephoneLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, numeroTelephoneLineEdit);

        labelPosition = new QLabel(formLayoutWidget);
        labelPosition->setObjectName(QString::fromUtf8("labelPosition"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelPosition);

        positionComboBox = new QComboBox(formLayoutWidget);
        positionComboBox->setObjectName(QString::fromUtf8("positionComboBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, positionComboBox);

        labelVazlidation = new QLabel(formLayoutWidget);
        labelVazlidation->setObjectName(QString::fromUtf8("labelVazlidation"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelVazlidation);

        validationPushButton = new QPushButton(formLayoutWidget);
        validationPushButton->setObjectName(QString::fromUtf8("validationPushButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, validationPushButton);

        horizontalLayoutWidget = new QWidget(AjoutJoueurInterfaceClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 491, 61));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        labelEnteteInterfaceAjoutJoueur = new QLabel(horizontalLayoutWidget);
        labelEnteteInterfaceAjoutJoueur->setObjectName(QString::fromUtf8("labelEnteteInterfaceAjoutJoueur"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelEnteteInterfaceAjoutJoueur->setFont(font);
        labelEnteteInterfaceAjoutJoueur->setTextFormat(Qt::RichText);
        labelEnteteInterfaceAjoutJoueur->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(labelEnteteInterfaceAjoutJoueur);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        retranslateUi(AjoutJoueurInterfaceClass);
        QObject::connect(validationPushButton, SIGNAL(clicked()), AjoutJoueurInterfaceClass, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(AjoutJoueurInterfaceClass);
    } // setupUi

    void retranslateUi(QDialog *AjoutJoueurInterfaceClass)
    {
        AjoutJoueurInterfaceClass->setWindowTitle(QApplication::translate("AjoutJoueurInterfaceClass", "AjoutJoueurInterface", 0, QApplication::UnicodeUTF8));
        labelprenom->setText(QApplication::translate("AjoutJoueurInterfaceClass", "Pr\303\251nom", 0, QApplication::UnicodeUTF8));
        labelNom->setText(QApplication::translate("AjoutJoueurInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
        labelDateNaissance->setText(QApplication::translate("AjoutJoueurInterfaceClass", "Date de Naissance", 0, QApplication::UnicodeUTF8));
        dateNaissanceDateEdit->setDisplayFormat(QApplication::translate("AjoutJoueurInterfaceClass", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        labelNumeroTelephone->setText(QApplication::translate("AjoutJoueurInterfaceClass", "Num\303\251ro de t\303\251l\303\251phone", 0, QApplication::UnicodeUTF8));
        labelPosition->setText(QApplication::translate("AjoutJoueurInterfaceClass", "Position", 0, QApplication::UnicodeUTF8));
        labelVazlidation->setText(QApplication::translate("AjoutJoueurInterfaceClass", "Validation", 0, QApplication::UnicodeUTF8));
        validationPushButton->setText(QApplication::translate("AjoutJoueurInterfaceClass", "Validation", 0, QApplication::UnicodeUTF8));
        labelEnteteInterfaceAjoutJoueur->setText(QApplication::translate("AjoutJoueurInterfaceClass", "Ajout  d'un joueur", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjoutJoueurInterfaceClass: public Ui_AjoutJoueurInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTJOUEURINTERFACE_H
