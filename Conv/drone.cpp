#include "drone.h"

//-----------------------Constructeurs-------------------
using namespace std;

Drone::Drone()
{
	log = ErreurConv();
	config.pathToUDPprog = "/";
	config.IPDrone = "192.168.1.1";
	compteur = 0;
	commande = "";

	temps = clock_t();
	tps_dernier_envoi = 0;

	current_roll=0;//en %ages
	current_pitch=0;//en %ages
	current_gaz=0;//en %ages
	current_yaw=0;//en %ages

}


//-------------------méthodes-----------------
//publiques :
bool Drone::isStable(string commande)
{
	//verification de la presence du programme d'envoi
	ifstream verif(config.pathToUDPprog + "Client_UDP");
	if (!verif)
	{
		log.pasProg();
		return false;
	}
	//verification '\r 'présent une seule fois (pas besoin de vérifier sil est présent a l a fin étant donné que 'envoi' s'occupe de l'ajouter)
	for (int i = 0; i < commande.length() - 1;i++)
	{
		if (commande[i] == '\r')
		{
			log.tropR();
			return false;
		}

	}

	//TODO a compléter

	return true;
}

void Drone::changerConfig(P_C_C param)
{
	config.pathToUDPprog = param.pathToUDPprog;
	config.IPDrone = param.IPDrone;
	config.portDrone = param.portDrone;
}

void Drone::resetCompteur()
{
	compteur = 0;
	log.rstC();
}
//privée	:
bool Drone::envoi()
{
	if (commande == "")
	{
		return false;
	}
	string aEnv = "./" + config.pathToUDPprog + "Client_UDP " + "5566 " + commande + '\r'; // ATTENTION : ce sont les sous programmes qui gèrent l'endroit ou est placé le comtpeur dans "commande" mais c'est ici qu'on l'incrémente après envoi

	if (isStable(aEnv))
	{
		log.logCommande(aEnv);
		//system(aEnv);
		compteur++;// C est ICI que l'on le gère
	}
	return true;
}

int Drone::convINT(int a)
{
	int tab[2][15] = { { -100, -75, -50, -25, -20, -10, -5, 0, 5, 10, 20, 25, 50, 75, 100 }, { -1082130432, -1086324736, -1090519040, -1098907648, -1102263091, -1110651699, -1119040307, 0, 1028443341, 1036831949, 1045220557, 1048576000, 1056964608, 1061158912, 1065353216 } };
	if (a == 0)
	{
		return 0;
	}

	int i = 0;
	int j = 14;
	while ((i < j) && (i < 14) && ((tab[0][i + 1] <= a) || (tab[0][j - 1] >= a)))
	{
		if (tab[0][i + 1] <= a)
			i++;
		if (tab[0][j - 1] >= a)
			j--;
	}
	if (abs(tab[0][i] - a) <= abs(tab[0][j] - a))
		return tab[1][i];
	else
		return tab[1][j];
}


