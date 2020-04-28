#include "annuairegui.h"
#include "Joueur.h"
#include "Annuaire.h"
#include "Entraineur.h"
#include "ajoutjoueurinterface.h"
#include "ajoutannuaireinterface.h"
#include "ajoutentraineurinterface.h"
#include <qmessagebox.h>
#include <iostream>

AnnuaireGUI::AnnuaireGUI(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.actionEntrerNomEquipe, SIGNAL(triggered()), this, SLOT(dialogAjoutAnnuaire()));
	QObject::connect(ui.actionJoueur, SIGNAL(triggered()), this, SLOT(dialogAjoutJoueur()));
	QObject::connect(ui.actionEntraineur, SIGNAL(triggered()), this, SLOT(dialogAjoutEntraineur()));

}

AnnuaireGUI::~AnnuaireGUI()
{

}

void AnnuaireGUI::dialogAjoutJoueur()
{
	if (m_annuaireCree == true)
	{
	AjoutJoueurInterface saisieJoueur(this);
		if(saisieJoueur.exec())
		{

			ajoutJoueur(saisieJoueur.reqNom().toStdString(),saisieJoueur.reqPrenom().toStdString(),
				    saisieJoueur.reqDateNaissance(), saisieJoueur.reqNumTelephone().toStdString(),
					saisieJoueur.reqPosition().toStdString());
			QString qstr = QString::fromStdString(m_annuaire.reqAnnuaireFormate());
			ui.textEditInfoEquipe->setText(qstr);
		}
    }
	else
	{
		QString message("Vous devez créer une équipe avant d'ajouter des joueurs");
				QMessageBox::information(this, "ERREUR", message);
				return;
	}
}


void AnnuaireGUI::dialogAjoutEntraineur()
{
	if (m_annuaireCree == true)
	{
	AjoutEntraineurInterface saisieEntraineur(this);
		if(saisieEntraineur.exec())
		{

			ajoutEntraineur(saisieEntraineur.reqNom().toStdString(),saisieEntraineur.reqPrenom().toStdString(),
				    saisieEntraineur.reqDateNaissance(), saisieEntraineur.reqNumTelephone().toStdString(),
					saisieEntraineur.reqNumRAMQ().toStdString(), saisieEntraineur.reqSexe());
			QString qstr = QString::fromStdString(m_annuaire.reqAnnuaireFormate());
			ui.textEditInfoEquipe->setText(qstr);
		}
    }
	else
	{
		QString message("Vous devez créer une équipe avant d'ajouter un entraîneur");
				QMessageBox::information(this, "ERREUR", message);
				return;
	}
}



void AnnuaireGUI::dialogAjoutAnnuaire()
{
	if (m_annuaireCree == false)
	{
		AjoutAnnuaireInterface saisieAnnuaire(this);
			if(saisieAnnuaire.exec())
			{
				ajoutAnnuaire(saisieAnnuaire.reqNomEquipe().toStdString());
			}
	}

}


void AnnuaireGUI::ajoutJoueur(std::string p_nom, std::string p_prenom, const util::Date& p_dateNaissance,
    		std::string p_telephone, std::string p_position)
{
	hockey::Joueur joueur(p_nom, p_prenom, p_dateNaissance, p_telephone, p_position);
	m_annuaire.ajouterPersonne(joueur);
}

void AnnuaireGUI::ajoutAnnuaire(std::string p_nomEquipe)
{
	hockey::Annuaire nouvelannuaire = hockey::Annuaire(p_nomEquipe);
	m_annuaire = nouvelannuaire;
	m_annuaireCree = true;
}

void AnnuaireGUI::ajoutEntraineur(std::string p_nom,std::string p_prenom,
				    const util::Date& p_dateNaissance, std::string p_telephone,
			        std::string p_numRAMQ, char p_sexe)
{
	hockey::Entraineur entraineur = hockey::Entraineur(p_nom, p_prenom, p_dateNaissance,
			                                p_telephone, p_numRAMQ, p_sexe);
	m_annuaire.ajouterPersonne(entraineur);
}