#ifndef DEF_P_E_C
#define DEF_P_E_C


#include <string>



typedef struct P_E_C P_E_C;

struct P_E_C //Param ERREUR Conversion en AT = ce qui sera affiché dans le log
{
	std::string pathEtNomLog;//ou toutes erreurs reportées
	int aff ;//priorité de ce qui est affiché : <0 => rien,  0 = erreur critique uniquement, 1= critique + operation non usuelle , 2= absolument tout

public:
	std::string aff_bool(bool bo) const
	{
		if (bo)
		{
			return("Oui");
		}
		else
		{
			return("Non");
		}
	}
	std::string toString()const
	{
		std::string str = "Ecriture dans : " + pathEtNomLog + "\n----Parametres d'Erreur:----\nOperations critiques :" + aff_bool(aff >= 0) + "\nOperations non usuelles :" + aff_bool(aff >= 1) + "\nToutes les operations :" + aff_bool(aff >= 2) + "\n----------------------------";
		return(str);
	}

};
std::ostream& operator<<(std::ostream & flux, P_E_C const & v);
std::string operator+(P_E_C const &v, std::string a);
std::string operator+(std::string a, P_E_C const &v);


#endif