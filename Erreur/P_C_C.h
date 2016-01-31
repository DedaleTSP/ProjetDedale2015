#ifndef DEF_P_C_C
#define DEF_P_C_C



#include <string>


typedef struct P_C_C P_C_C;
struct P_C_C//Param config conversion en AT
{
public:
	std::string pathToUDPprog;
	std::string IPDrone;
	std::string portDrone; // inutilisé pour l'instant


public:	
	std::string toString()const
	{
		std::string str = "Parametres de la conversion AT: \n Chemin du programme UDP :" + pathToUDPprog + "\n Ip du Drone :" + IPDrone + "\n Port du Drone :" + portDrone;
		return(str);
	}
};
std::ostream &operator<<(std::ostream & flux, P_C_C const & v);
std::string operator+(P_C_C const &v, std::string a);
std::string operator+(std::string a, P_C_C const &v);
#endif