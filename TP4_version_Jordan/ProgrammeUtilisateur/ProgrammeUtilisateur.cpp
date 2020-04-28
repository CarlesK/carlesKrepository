/**
 * @file : ProgrammeUtilisateur.cpp
 * @date : 2020-04-02
 * @author : Jordan
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Personne.h"
#include "Date.h"
#include "Joueur.h"
#include "Entraineur.h"
#include "Annuaire.h"
#include "validationFormat.h"

using namespace std;
using namespace hockey;
using namespace util;
int main()
{

 cout<<"Bienvenue à l'outil d'ajout d'une personne"<<endl;
 cout<<"-----------------------------------------"<<endl;
 //Demander le nom du joueur et valider
 cout<<"Entrez le nom du joueur"<<endl;
 string nomJoueur;
 cin>>nomJoueur;
 while (validerFormatNom(nomJoueur)== 0)
 	{
 		cout<< "Le nom de la personne ne doit "<<
 				"comporter que des lettres"<<endl;
 		cout<< "Entrez le nom de la personne"<< endl;
 		cin >> nomJoueur;
 	}

 //Demander le prénom du joueur et valider
 cout<<"Entrez le prénom du joueur"<<endl;
 string prenomJoueur;
 cin>>prenomJoueur;
 while (validerFormatNom(prenomJoueur)== 0)
 	{
 		cout<< "Le nom de la personne ne doit "<<
 				"comporter que des lettres"<<endl;
 		cout<< "Entrez le nom de la personne"<< endl;
 		cin >> prenomJoueur;
 	}

 //Demander le numéro de téléphone et valider
 cout<<"Entrez le numéro de téléphone du joueur (XXX XXX-XXXX)"<<endl;
 string numTelephoneJoueur;
 cin.ignore();
 getline(cin, numTelephoneJoueur);
 while(validerTelephone(numTelephoneJoueur) == false)
 {
	 cout<<"Le numéro doit avoir un format national canadien"<<endl;
	 cout<<"Entrez le numéro de téléphone du joueur (XXX XXX-XXXX)"<<endl;
     getline(cin, numTelephoneJoueur);
 }

 //Demander la date de naissance et valider + valider entre 15 et 17
 cout<<"Veuillez entrer sa date de naissance"<<endl;
 cout<<"Le jour [1...31]";
 long jourNaissanceJoueur;
 cin>>jourNaissanceJoueur;
 cout<<"Le mois [1...31]";
 long moisNaissanceJoueur;
 cin>>moisNaissanceJoueur;
 cout<<"L'année [1975...]";
 long anneeNaissanceJoueur;
 cin>>anneeNaissanceJoueur;
 while(Date::validerDate(jourNaissanceJoueur,
		                 moisNaissanceJoueur,
						 anneeNaissanceJoueur) == 0)
 {
	 cout<<"Date invalide"<<endl;
	 cout<<"Cette date est impossible"<<endl;
	 cout<<"Veuillez entrer sa date de naissance"<<endl;
	 cout<<"Le jour [1...31]";
	 cin>>jourNaissanceJoueur;
	 cout<<"Le mois [1...31]";
	 cin>>moisNaissanceJoueur;
	 cout<<"L'année [1975...]";
	 cin>>anneeNaissanceJoueur;
 }
 	 Date ddnJoueur = Date(jourNaissanceJoueur,
 			               moisNaissanceJoueur,
						   anneeNaissanceJoueur);
 while(validerAgeJoueur(ddnJoueur)==0)
 {
 		cout<<"Date invalide"<<endl;
 			 cout<<"Le joueur n'est pas âgé entre 15 et 17 ans"<<endl;
 			 cout<<"Veuillez entrer sa date de naissance"<<endl;
 			 cout<<"Le jour [1...31]";
 			 cin>>jourNaissanceJoueur;
 			 cout<<"Le mois [1...31]";
 			 cin>>moisNaissanceJoueur;
 			 cout<<"L'année [1975...]";
 			 cin>>anneeNaissanceJoueur;
 			 ddnJoueur.asgDate(jourNaissanceJoueur,
 					           moisNaissanceJoueur,
							   anneeNaissanceJoueur);
 }

 //Demander la position du joueur
 cout<<"Entrez la position du joueur(ailier, centre, défenseur, gardien)"<<endl;
 string positionJoueur;
 cin>>positionJoueur;
 while(validerPosition(positionJoueur)==0)
 {
	 cout<<"La position est invalide"<<endl;
	 cout<<"Entrez la position du joueur(ailier, centre, défenseur, gardien)"<<endl;
	 cin>>positionJoueur;
 }

 // ---------------------------------------------------------------------

 //Demander le nom de l'entraîneur et valider
  cout<<"Entrez le nom de l'entraîneur"<<endl;
  string nomEntraineur;
  cin>>nomEntraineur;
  while (validerFormatNom(nomEntraineur)== 0)
  	{
  		cout<< "Le nom de la personne ne doit "<<
  				"comporter que des lettres"<<endl;
  		cout<< "Entrez le nom de la personne"<< endl;
  		cin >> nomEntraineur;
  	}

  //Demander le prénom de l'entraîneur et valider
  cout<<"Entrez le prénom de l'entraîneur"<<endl;
  string prenomEntraineur;
  cin>>prenomEntraineur;
  while (validerFormatNom(prenomEntraineur)== 0)
  	{
  		cout<< "Le nom de la personne ne doit "<<
  				"comporter que des lettres"<<endl;
  		cout<< "Entrez le nom de la personne"<< endl;
  		cin >> prenomEntraineur;
  	}

  //Demander le numéro de téléphone et valider
  cout<<"Entrez le numéro de téléphone de l'entraîneur (XXX XXX-XXXX)"<<endl;
  string numTelephoneEntraineur;
  cin.ignore();
  getline(cin, numTelephoneEntraineur);
  while(validerTelephone(numTelephoneEntraineur) == false)
  {
 	 cout<<"Le numéro doit avoir un format national canadien"<<endl;
 	 cout<<"Entrez le numéro de téléphone du joueur (XXX XXX-XXXX)"<<endl;
      getline(cin, numTelephoneEntraineur);
  }

  //Demander la date de naissance et valider + valider majeur
  cout<<"Veuillez entrer sa date de naissance"<<endl;
  cout<<"Le jour [1...31]";
  long jourNaissanceEntraineur;
  cin>>jourNaissanceEntraineur;
  cout<<"Le mois [1...31]";
  long moisNaissanceEntraineur;
  cin>>moisNaissanceEntraineur;
  cout<<"L'année [1975...]";
  long anneeNaissanceEntraineur;
  cin>>anneeNaissanceEntraineur;
  while(Date::validerDate(jourNaissanceEntraineur,
 		                 moisNaissanceEntraineur,
 						 anneeNaissanceEntraineur) == 0)
  {
 	 cout<<"Date invalide"<<endl;
 	 cout<<"Cette date est impossible"<<endl;
 	 cout<<"Veuillez entrer sa date de naissance"<<endl;
 	 cout<<"Le jour [1...31]";
 	 cin>>jourNaissanceEntraineur;
 	 cout<<"Le mois [1...31]";
 	 cin>>moisNaissanceEntraineur;
 	 cout<<"L'année [1975...]";
 	 cin>>anneeNaissanceEntraineur;
  }
  	 Date ddnEntraineur = Date(jourNaissanceEntraineur,
  			               moisNaissanceEntraineur,
 						   anneeNaissanceEntraineur);
  while(validerAgeEntraineur(ddnEntraineur)==0)
  {
  		cout<<"Date invalide"<<endl;
  			 cout<<"L'entraîneur doit être majeur (>18 ans)"<<endl;
  			 cout<<"Veuillez entrer sa date de naissance"<<endl;
  			 cout<<"Le jour [1...31]";
  			 cin>>jourNaissanceEntraineur;
  			 cout<<"Le mois [1...31]";
  			 cin>>moisNaissanceEntraineur;
  			 cout<<"L'année [1975...]";
  			 cin>>anneeNaissanceEntraineur;
  			 ddnEntraineur.asgDate(jourNaissanceEntraineur,
  					           moisNaissanceEntraineur,
 							   anneeNaissanceEntraineur);
  }

  // Demander le sexe de l'entraîneur et valider
  cout << "Veuillez entrer le sexe de l'entraîneur (M ou F)" << endl;
  char sexeEntraineur;
  cin >> sexeEntraineur;
  while( validerSexe( sexeEntraineur)==0)
  {
	  cout << "Sexe invalide" << endl;
	  cout << "Veuillez entrer le sexe de l'entraîneur (M ou F)" << endl;
	  cin >> sexeEntraineur;
  }

  // Demander le numéro de RAMQ de l'entraîneur
  cout << "Veuillez entrer le numéro de RAMQ de l'entraîneur" << endl;
  string numRAMQEntraineur;
  cin.ignore();
  getline(cin, numRAMQEntraineur);
  while( validerNumRAMQ( numRAMQEntraineur, nomEntraineur,
		               prenomEntraineur, jourNaissanceEntraineur,
					   moisNaissanceEntraineur, anneeNaissanceEntraineur,
					   sexeEntraineur)==0)
    {
  	  cout << "Format ou numéro de RAMQ invalide" << endl;
  	  cout << "Veuillez entrer le numéro de RAMQ de l'entraîneur" << endl;
  	  cin.ignore();
  	  getline(cin, numRAMQEntraineur);
    }

  Joueur joueur1 = Joueur(nomJoueur, prenomJoueur, ddnJoueur,
		                  numTelephoneJoueur, positionJoueur);
  Entraineur entraineur1 = Entraineur(nomEntraineur,prenomEntraineur,
		                              ddnEntraineur,numTelephoneEntraineur,
									  numRAMQEntraineur,sexeEntraineur);

  Annuaire annuaire1 = Annuaire("winners de hockeyville");
  annuaire1.ajouterPersonne(joueur1);
  annuaire1.ajouterPersonne(entraineur1);
  cout<<annuaire1.reqAnnuaireFormate();
 return 0;
}



