#include "ajoutentraineurinterface.h"
#include <qmessagebox.h>
#include "validationFormat.h"

AjoutEntraineurInterface::AjoutEntraineurInterface(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.sexeComboBox->addItem("Masculin");
	ui.sexeComboBox->addItem("Féminin");
}

AjoutEntraineurInterface::~AjoutEntraineurInterface()
{

}

QString AjoutEntraineurInterface::reqNom() const
{
	return ui.nomLineEdit_2->text();
}

QString AjoutEntraineurInterface::reqPrenom() const
{
	return ui.prenomLineEdit_2->text();
}

util::Date AjoutEntraineurInterface::reqDateNaissance() const
{
	return m_dateNaissance;
}

QString AjoutEntraineurInterface::reqNumTelephone() const
{
	return ui.numeroTelephoneLineEdit_2->text();
}

QString AjoutEntraineurInterface::reqNumRAMQ() const
{
	return ui.numRAMQLineEdit->text();
}
char AjoutEntraineurInterface::reqSexe() const
{
	if(ui.sexeComboBox->currentText().toStdString()=="Masculin")
	{
		char charsexe = 'M';
		return charsexe;
	}

	        char charsexe = 'F';
			return charsexe;
}
void AjoutEntraineurInterface::valideEnregistrement()
{
	if(util::validerFormatNom(ui.nomLineEdit_2->text().toStdString())==0)
	{
		QString message("Le nom doit être non vide et valide.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(util::validerFormatNom(ui.prenomLineEdit_2->text().toStdString())==0)
		{
			QString message("Le prénom doit être non vide et valide.");
			QMessageBox::information(this, "ERREUR", message);
			return;
		}
	if(util::validerTelephone(ui.numeroTelephoneLineEdit_2->text().toStdString())==0)
		{
			QString message("Le numéro de téléphone ne doit pas être vide.");
			QMessageBox::information(this, "ERREUR", message);
			return;
		}

	m_dateNaissance.asgDate(ui.dateNaissanceDateEdit_2->date().day(),
			                ui.dateNaissanceDateEdit_2->date().month(),
							ui.dateNaissanceDateEdit_2->date().year());
	if(util::validerAgeEntraineur(m_dateNaissance) == 0)
		{
				QString message("L'entraîneur doit être majeur.");
				QMessageBox::information(this, "ERREUR", message);
				return;
		}

	if(util::validerNumRAMQ(reqNumRAMQ().toStdString(),
			                reqNom().toStdString(),
			                reqPrenom().toStdString(),
							ui.dateNaissanceDateEdit_2->date().day(),
							ui.dateNaissanceDateEdit_2->date().month(),
							ui.dateNaissanceDateEdit_2->date().year(),
							reqSexe())==0)
		{
					QString message("Le numéro de RAMQ doit être valide et avoir un format valide.");
					QMessageBox::information(this, "ERREUR", message);
					return;
		}

	accept();
}
