#include "ajoutannuaireinterface.h"
#include <qmessagebox.h>

AjoutAnnuaireInterface::AjoutAnnuaireInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

QString AjoutAnnuaireInterface::reqNomEquipe() const
{
	return ui.lineEditNomEquipe->text();
}

void AjoutAnnuaireInterface::validerEnregistrement()
{
	if(ui.lineEditNomEquipe->text().isEmpty())
	{
		QString message("Le nom ne doit pas être vide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	accept();
}

AjoutAnnuaireInterface::~AjoutAnnuaireInterface()
{

}