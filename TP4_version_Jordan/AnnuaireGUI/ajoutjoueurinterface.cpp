#include "ajoutjoueurinterface.h"
#include <qmessagebox.h>
#include "validationFormat.h"

AjoutJoueurInterface::AjoutJoueurInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.positionComboBox->addItem("centre");
	ui.positionComboBox->addItem("ailier");
	ui.positionComboBox->addItem("défenseur");
	ui.positionComboBox->addItem("gardien");
}

AjoutJoueurInterface::~AjoutJoueurInterface()
{

}

QString AjoutJoueurInterface::reqNom() const
{
	return ui.nomLineEdit->text();
}

QString AjoutJoueurInterface::reqPrenom() const
{
	return ui.prenomLineEdit->text();
}

util::Date AjoutJoueurInterface::reqDateNaissance() const
{
	return m_dateNaissance;
}

QString AjoutJoueurInterface::reqNumTelephone() const
{
	return ui.numeroTelephoneLineEdit->text();
}

QString AjoutJoueurInterface::reqPosition() const
{
	return ui.positionComboBox->currentText();
}
void AjoutJoueurInterface::valideEnregistrement()
{
	if(util::validerFormatNom(reqNom().toStdString()) == 0)
	{
		QString message("Le nom doit être valide et non vide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(util::validerFormatNom(reqPrenom().toStdString()) == 0)
		{
			QString message("Le prénom ne doit pas être vide.");
			QMessageBox::information(this, "ERREUR", message);
			return;
		}
	if(util::validerTelephone(reqNumTelephone().toStdString()) == 0)
		{
			QString message("Le numéro de téléphone ne doit pas être vide.");
			QMessageBox::information(this, "ERREUR", message);
			return;
		}
	m_dateNaissance.asgDate(ui.dateNaissanceDateEdit->date().day(),
			                ui.dateNaissanceDateEdit->date().month(),
							ui.dateNaissanceDateEdit->date().year());
	if(util::validerAgeJoueur(m_dateNaissance) == 0)
			{
					QString message("Le joueur doit être âgé entre 15 et 17 ans.");
					QMessageBox::information(this, "ERREUR", message);
					return;
			}
	accept();
}