#ifndef DEF_P_C_C
#define DEF_P_C_C



#include <string>
#include <iostream>

typedef struct P_C_C P_C_C;
struct P_C_C//Param config conversion en AT
{
public:
	std::string pathToUDPprog;
	std::string IPDrone;
	std::string portDrone; // inutilisť pour l'instant
	int tempsEntreEnvois;//le temps entre 2 envois de commadnes au drone en ms


public:
	std::string toString()const
	{
		std::string str = "Parametres de la conversion AT: \n Chemin du programme UDP :" + pathToUDPprog + "\n Ip du Drone :" + IPDrone + "\n Port du Drone :" + portDrone;
		str += "\nDt=" + std::to_string(tempsEntreEnvois) + " ms";
		return(str);
	}
};
std::ostream &operator<<(std::ostream & flux, P_C_C const & v);
std::string operator+(P_C_C const &v, std::string a);
std::string operator+(std::string a, P_C_C const &v);
#endif
