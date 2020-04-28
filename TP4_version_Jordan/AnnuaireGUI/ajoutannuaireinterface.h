#ifndef AJOUTANNUAIREINTERFACE_H
#define AJOUTANNUAIREINTERFACE_H

#include <QtGui/QDialog>
#include "ui_ajoutannuaireinterface.h"

class AjoutAnnuaireInterface : public QDialog
{
    Q_OBJECT

public:
    AjoutAnnuaireInterface(QWidget *parent = 0);
    QString reqNomEquipe() const;
    ~AjoutAnnuaireInterface();

private slots:
	void validerEnregistrement();

private:
    Ui::AjoutAnnuaireInterfaceClass ui;
};

#endif // AJOUTANNUAIREINTERFACE_H