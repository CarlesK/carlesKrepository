#ifndef AJOUTENTRAINEURINTERFACE_H
#define AJOUTENTRAINEURINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajoutentraineurinterface.h"
#include "Date.h"

class AjoutEntraineurInterface : public QDialog
{
    Q_OBJECT

public:
    AjoutEntraineurInterface(QWidget *parent = 0);
    ~AjoutEntraineurInterface();
    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDateNaissance() const;
    QString reqNumTelephone() const;
    QString reqNumRAMQ() const;
    char   reqSexe() const;

private slots:
	void valideEnregistrement();

private:
    Ui::AjoutEntraineurInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // AJOUTENTRAINEURINTERFACE_H