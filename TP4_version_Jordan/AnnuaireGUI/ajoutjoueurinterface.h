#ifndef AJOUTJOUEURINTERFACE_H
#define AJOUTJOUEURINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajoutjoueurinterface.h"
#include "Date.h"

class AjoutJoueurInterface : public QDialog
{
    Q_OBJECT

public:
    AjoutJoueurInterface(QWidget *parent = 0);
    ~AjoutJoueurInterface();
    QString reqNom() const;
    QString reqPrenom() const;
    util::Date reqDateNaissance() const;
    QString reqNumTelephone() const;
    QString reqPosition() const;


private slots:
	void valideEnregistrement();

private:
    Ui::AjoutJoueurInterfaceClass ui;
    util::Date m_dateNaissance;
};

#endif // AJOUTJOUEURINTERFACE_H