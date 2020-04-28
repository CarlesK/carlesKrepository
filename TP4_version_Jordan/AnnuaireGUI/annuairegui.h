#ifndef ANNUAIREGUI_H
#define ANNUAIREGUI_H

#include <QtGui/QMainWindow>
#include "ui_annuairegui.h"
#include "Personne.h"
#include "Annuaire.h"

class AnnuaireGUI : public QMainWindow
{
    Q_OBJECT

public:
    AnnuaireGUI(QWidget *parent = 0);
    ~AnnuaireGUI();
    void ajoutJoueur(std::string p_nom, std::string p_prenom, const util::Date& p_dateNaissance,
    		std::string p_telephone, std::string p_position);
    void ajoutAnnuaire(std::string p_nomEquipe);
    void ajoutEntraineur(std::string p_nom,std::string p_prenom,
		    const util::Date& p_dateNaissance, std::string p_telephone,
	        std::string p_numRAMQ, char p_sexe);

private slots:
	void dialogAjoutJoueur();
	void dialogAjoutAnnuaire();
	void dialogAjoutEntraineur();

private:
    Ui::AnnuaireGUIClass ui;
    hockey::Annuaire m_annuaire;
    bool m_annuaireCree = false;


};

#endif // ANNUAIREGUI_H
