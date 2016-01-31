#include "P_E_C.h"

// Ces fichier .cpp evite une erreur de compilation disant qu'il y a plusieurs definitions d'une même fonction
//à cause des include multiples nécessaires
std::ostream& operator<<(std::ostream & flux, P_E_C const & v)
{
	std::string mess = v.toString();
	flux << mess << std::endl;
	return flux;
}


std::string operator+(P_E_C const &v, std::string a)
{
	std::string mess = v.toString();
	return(mess + a);
}
std::string operator+(std::string a, P_E_C const &v)
{
	std::string mess = v.toString();
	return(a + mess);
}
