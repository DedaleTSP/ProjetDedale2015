#ifndef DEF_DRONE
#define DEF_DRONE


#include <iostream>
#include <fstream>

#include <ctime>


#include "CtPD.h"
#include "P_C_C.h"


class Drone
{
	P_C_C config;
	int compteur; // numéro du paquet envoyé au drone
	std::string commande;//commande qui va etre envoyée
	//table de conversion
	clock_t temps;
	double tps_dernier_envoi;

	int current_roll;//en %ages*100
	int current_pitch;//en %ages*100
	int current_gaz;//en %ages*100
	int current_yaw;//en %ages*100


public:
	ErreurConv log; //remarque : ainsi pour changer paramètres du log (ce qui est affiché ou l'endroti ou il est ), passer directement par drone.log.change_param(...) ou drone.log.change_log(...)

	
	
public:
	Drone();
	bool isStable(std::string commande);
	void resetCompteur();
	void changerConfig(P_C_C param);
	std::string comR_Mouv(int roll=0,int pitch=0,int gaz=0,int yaw=0);//mouvement relatif = dit pas de quel angle on le change mais de combien vont changer les current_roll/pitch/yaw ...
private:
	bool envoi();
	int convINT(int a);//converti un int en %age*100 au vrai int correspondant a cette valeur





};


#endif