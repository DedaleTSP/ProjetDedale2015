#ifndef DEF_ErreurConv
#define DEF_ErreurConv

#include "Erreur.h"

class ErreurConv : public Erreur
{
public:
	//a REMPLACER :
	ErreurConv(P_E_C param = { "D:/DEDALE/Log/LogConv.txt", 1 });
	//a decommenter : ErreurConv(P_E_C param = { "~/.ARDroneFlightController/Log/LogConv.txt", 1 });

	bool logCommande(std::string com);//ecrit une commande qui a été envoyé au drone par l'objet drone dans le log
	bool pasProg();//indique que l'objet conv ne trouve pas le programme des vieux dans le repertoire indiqué
	bool tropR();//l'objet conv a essaye d'envoyer une commande contenant plus d'un '\r' (qui termine un message pour le drone)
	bool rstC();//le compteur du convertisseur a été remis a zéro	
};


#endif
