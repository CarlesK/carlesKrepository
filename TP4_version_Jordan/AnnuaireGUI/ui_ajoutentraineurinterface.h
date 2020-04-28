/********************************************************************************
** Form generated from reading UI file 'ajoutentraineurinterface.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTENTRAINEURINTERFACE_H
#define UI_AJOUTENTRAINEURINTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AjoutEntraineurInterfaceClass
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *labelprenom_2;
    QLineEdit *prenomLineEdit_2;
    QLabel *labelNom_2;
    QLineEdit *nomLineEdit_2;
    QLabel *labelDateNaissance_2;
    QDateEdit *dateNaissanceDateEdit_2;
    QLabel *labelNumeroTelephone_2;
    QLineEdit *numeroTelephoneLineEdit_2;
    QLabel *labelPosition_2;
    QComboBox *sexeComboBox;
    QLabel *labelVazlidation_2;
    QPushButton *validationPushButton_2;
    QLabel *label;
    QLineEdit *numRAMQLineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelEnteteInterfaceAjoutJoueur_2;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *AjoutEntraineurInterfaceClass)
    {
        if (AjoutEntraineurInterfaceClass->objectName().isEmpty())
            AjoutEntraineurInterfaceClass->setObjectName(QString::fromUtf8("AjoutEntraineurInterfaceClass"));
        AjoutEntraineurInterfaceClass->resize(508, 383);
        formLayoutWidget = new QWidget(AjoutEntraineurInterfaceClass);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 60, 481, 301));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout_2->setFormAlignment(Qt::AlignCenter);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        labelprenom_2 = new QLabel(formLayoutWidget);
        labelprenom_2->setObjectName(QString::fromUtf8("labelprenom_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelprenom_2);

        prenomLineEdit_2 = new QLineEdit(formLayoutWidget);
        prenomLineEdit_2->setObjectName(QString::fromUtf8("prenomLineEdit_2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, prenomLineEdit_2);

        labelNom_2 = new QLabel(formLayoutWidget);
        labelNom_2->setObjectName(QString::fromUtf8("labelNom_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelNom_2);

        nomLineEdit_2 = new QLineEdit(formLayoutWidget);
        nomLineEdit_2->setObjectName(QString::fromUtf8("nomLineEdit_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, nomLineEdit_2);

        labelDateNaissance_2 = new QLabel(formLayoutWidget);
        labelDateNaissance_2->setObjectName(QString::fromUtf8("labelDateNaissance_2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelDateNaissance_2);

        dateNaissanceDateEdit_2 = new QDateEdit(formLayoutWidget);
        dateNaissanceDateEdit_2->setObjectName(QString::fromUtf8("dateNaissanceDateEdit_2"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, dateNaissanceDateEdit_2);

        labelNumeroTelephone_2 = new QLabel(formLayoutWidget);
        labelNumeroTelephone_2->setObjectName(QString::fromUtf8("labelNumeroTelephone_2"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelNumeroTelephone_2);

        numeroTelephoneLineEdit_2 = new QLineEdit(formLayoutWidget);
        numeroTelephoneLineEdit_2->setObjectName(QString::fromUtf8("numeroTelephoneLineEdit_2"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, numeroTelephoneLineEdit_2);

        labelPosition_2 = new QLabel(formLayoutWidget);
        labelPosition_2->setObjectName(QString::fromUtf8("labelPosition_2"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, labelPosition_2);

        sexeComboBox = new QComboBox(formLayoutWidget);
        sexeComboBox->setObjectName(QString::fromUtf8("sexeComboBox"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, sexeComboBox);

        labelVazlidation_2 = new QLabel(formLayoutWidget);
        labelVazlidation_2->setObjectName(QString::fromUtf8("labelVazlidation_2"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, labelVazlidation_2);

        validationPushButton_2 = new QPushButton(formLayoutWidget);
        validationPushButton_2->setObjectName(QString::fromUtf8("validationPushButton_2"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, validationPushButton_2);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label);

        numRAMQLineEdit = new QLineEdit(formLayoutWidget);
        numRAMQLineEdit->setObjectName(QString::fromUtf8("numRAMQLineEdit"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, numRAMQLineEdit);

        horizontalLayoutWidget = new QWidget(AjoutEntraineurInterfaceClass);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 10, 491, 51));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        labelEnteteInterfaceAjoutJoueur_2 = new QLabel(horizontalLayoutWidget);
        labelEnteteInterfaceAjoutJoueur_2->setObjectName(QString::fromUtf8("labelEnteteInterfaceAjoutJoueur_2"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelEnteteInterfaceAjoutJoueur_2->setFont(font);
        labelEnteteInterfaceAjoutJoueur_2->setTextFormat(Qt::RichText);
        labelEnteteInterfaceAjoutJoueur_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(labelEnteteInterfaceAjoutJoueur_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        retranslateUi(AjoutEntraineurInterfaceClass);
        QObject::connect(validationPushButton_2, SIGNAL(clicked()), AjoutEntraineurInterfaceClass, SLOT(valideEnregistrement()));

        QMetaObject::connectSlotsByName(AjoutEntraineurInterfaceClass);
    } // setupUi

    void retranslateUi(QWidget *AjoutEntraineurInterfaceClass)
    {
        AjoutEntraineurInterfaceClass->setWindowTitle(QApplication::translate("AjoutEntraineurInterfaceClass", "AjoutEntraineurInterface", 0, QApplication::UnicodeUTF8));
        labelprenom_2->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Pr\303\251nom", 0, QApplication::UnicodeUTF8));
        labelNom_2->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Nom", 0, QApplication::UnicodeUTF8));
        labelDateNaissance_2->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Date de Naissance", 0, QApplication::UnicodeUTF8));
        dateNaissanceDateEdit_2->setDisplayFormat(QApplication::translate("AjoutEntraineurInterfaceClass", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        labelNumeroTelephone_2->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Num\303\251ro de t\303\251l\303\251phone", 0, QApplication::UnicodeUTF8));
        labelPosition_2->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Sexe", 0, QApplication::UnicodeUTF8));
        labelVazlidation_2->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Validation", 0, QApplication::UnicodeUTF8));
        validationPushButton_2->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Validation", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Num\303\251ro de RAMQ", 0, QApplication::UnicodeUTF8));
        labelEnteteInterfaceAjoutJoueur_2->setText(QApplication::translate("AjoutEntraineurInterfaceClass", "Ajout  d'un Entra\303\256neur", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AjoutEntraineurInterfaceClass: public Ui_AjoutEntraineurInterfaceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTENTRAINEURINTERFACE_H
