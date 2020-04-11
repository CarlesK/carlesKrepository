/*
 * validatonFormat.cpp
 *
 *  Created on: 2020-02-15
 *      Author: etudiant
 */


/*
 * validationFormat.cpp
 *
 *  Created on: 2020-02-15
 *      Author: Carles Kouaya
 */

#include <iostream>
#include "validationFormat.h"
#include <string>
#include<algorithm>
#include <regex>

using namespace std;

namespace util{

bool validerTelephone(const std:: string& p_telephone)
{
    bool est_valide = true;
    string str = p_telephone;

    static const std::string pattern = "dddddddddd" ; // use <regex> ?

   str.erase(remove(str.begin(), str.end(), '-'), str.end()); //remove '-' from string
   str.erase(remove(str.begin(), str.end(), '('), str.end()); //remove '(' from string
   str.erase(remove(str.begin(), str.end(), ')'), str.end()); //remove ')' from string
   str.erase(remove(str.begin(), str.end(), ' '), str.end()); //remove ' ' from string


    if( str.size() != pattern.size() ) return false ;

    for( unsigned i = 0 ; i < str.size() ; i++ )
    {
        if( pattern[i] == 'd' ) // digit expected
        {
            if( !isdigit( str[i] ) )
            {
            	est_valide = false;
            }
            else
            {
              if ((i == 0|| i==2 ) && str[i] <'2')
              {
            	  est_valide = false;
              }

              if (i==1 && (str[i]=='2' || str[i]=='9'))
              {
            	  est_valide = false;
              }

            }

        }

    }

    return est_valide ;
}



bool validerNumRAMQ(const std::string& p_numero, const std::string& p_nom, const std::string& p_prenom, int p_jourNaissance, int p_moisNaissance, int p_anneeNaissance, char p_sex)
  {
	 bool estValide_Numero = true;

	 std::string p_nomStr = conversionMinuscule(SupprimerEspaces(p_nom).substr(0,3));
	 std::string p_prenomStr = conversionMinuscule(SupprimerEspaces(p_prenom).substr(0,1));
	 std::string p_numeroStr = SupprimerEspaces(conversionMinuscule(p_numero));

    static const std::string pattern = "xxxxdddddddd" ; //  could use regex  object  but isnt supported by this version of eclipse

    if( p_numeroStr.size() != pattern.size() )
    {
    	return false ;
    }

    for( unsigned i = 0 ; i <  p_numeroStr.size() ; i++ )
    {

        if (i<=3)
        {

          if (isdigit(p_numeroStr[i]))
          {
        	  estValide_Numero = false;
          }
          else
          {
            if (p_numeroStr[i] <'A'||p_numeroStr[i]>'z')
             {
            	estValide_Numero = false;
             }

             if (p_numeroStr[i]>'Z' &&  p_numeroStr[i]<'a')
             {
            	 estValide_Numero = false;
             }

          }

        }
        else
        {
            if(!isdigit((p_numeroStr[i])))
            {
            	estValide_Numero = false;
            }
            else if((i==6 && p_numeroStr[i]>'1') ||(i==8 && p_numeroStr[i]>'3'))
            {
            	estValide_Numero = false;
            }

        }

    }

     if ( (p_numeroStr.substr(0,4) == (p_nomStr + p_prenomStr)))
     {
        estValide_Numero = true;
     }

	  int p_deuxDernierChiffres = (p_anneeNaissance % 100);

	  bool estValide_anneeNaissance = true;

	  if ((std::stoi(p_numeroStr.substr(4,2)) == p_deuxDernierChiffres))
	   {
         estValide_anneeNaissance = true;
      }
	  else
      {
	   estValide_anneeNaissance  = false;
      }

	  bool estValide_moisNaissance = true;

	  int ajustement_Mois = (p_sex == 'F' ? 50 : 0);

	  if ( std::stoi(p_numeroStr.substr(6,2)) == (p_moisNaissance + ajustement_Mois) && (p_moisNaissance < MAX_MOIS))
	   {
          estValide_moisNaissance = true;
       }else
       {
	     estValide_moisNaissance  = false;
       }

	  bool estValide_jourNaissance = true;

	  if ((std::stoi(p_numeroStr.substr(8,2)) == p_jourNaissance) && (p_jourNaissance < MAX_JOUR))
	   {
         estValide_jourNaissance = true;
       }
	  else
      {
	   estValide_jourNaissance  = false;
       }

	 return  estValide_Numero && estValide_anneeNaissance && estValide_moisNaissance && estValide_jourNaissance;

 }



bool validerFormatNom(const std ::string& p_nom)
{
	bool est_valide = true;

    for( unsigned i = 0 ; i <  p_nom.size() ; i++ )
    {

      if ( (p_nom[i] <'A')||(p_nom[i]>'z'))
      {
    	  est_valide = false;
      }


      if ( p_nom[i]>'Z' &&  p_nom[i]<'a')
      {
    	  est_valide = false;
      }

    }

    return est_valide ;
}




/**
 * \brief retourne la chaine de caractere passée en paramètre en la convertissant en minuscule

 * \param[in] string p_texte la chaine de caracteres à traiter

 * \return retourne la chaine de caractere passée en paramètre en la convertissant en minuscule

 */


 string conversionMinuscule (string p_texte)
{
  unsigned int dim = p_texte.size();
  for ( unsigned i=0; i< dim ;i++)
  {
   p_texte [i] =  (char) tolower( p_texte [i]);
  }
  return p_texte;
}

 string conversionMajuscule (string p_texte)
{
  unsigned int dim = p_texte.size();
  for ( unsigned i=0; i< dim ;i++)
  {
   p_texte [i] =  (char) toupper( p_texte [i]);
  }
  return p_texte;
}



/**

 * \brief retourne la chaine de caractere passée en paramètre en supprimant tous les espaces

 * \param[in] std::string str la chaine de caracteres à traiter

 * \return la chaine de caractere passée en paramètre en supprimant tous les espaces

 */


std::string SupprimerEspaces(std::string str)
{
    std::string strSansEspace;

    for (char c: str) {

	  if (c != ' ')
	  {
	   strSansEspace = strSansEspace + c;
	  }

	}

    return strSansEspace;
 }

}










