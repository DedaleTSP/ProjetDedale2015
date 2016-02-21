#ifndef DEF_Erreur
#define DEF_Erreur


#include <iostream>
#include <fstream>
#include "P_E_C.h"
#include <cmath>
#include <stdlib.h>


class Erreur// methodes de gestions et d'afficahges d'affichage dans un log
{

private://variable
	P_E_C param;//en gros c'est un int et un string et un overwrite de operator<< pour afficher le choix
public://fonctions
	Erreur(P_E_C param2 = { "~/.ARDroneFlightController/Log/LogConv.txt", 1 });
	//POUR UNIX METTRE par exemple(pas obligatoire si utilise pas le constructeur sans argument):
	//Erreur(P_E_C param2 = { "~/Dedale_Test_Log/LogConv.txt", 1 });
	bool change_log(std::string path);
	bool change_param(P_E_C nouv);
	bool change_param(int param);
	bool change_param(bool aff_critique, bool aff_non_usu, bool aff_tout);
	void trouve_bon_nom();
	P_E_C get_param()const;

protected:
	//interraction directe avec l'utilisateur, plus tard faudra remplacer
	//cin et cout pour utilsier la vraie interface utilisateur
	std::string demande_info(std::string question = "");
	void affiche_direct(std::string mess = "");

	//INTERRUPTIONs
	void interr_lethal(std::string mess = "");//juste utilisée si impossible ecrire dans log, fait tout quitter si c'est le cas

	//ecrit un message (de nimporte quel type)dans le log
	bool Log(std::string mess, int priorite);
private:
	bool verif_path_txt();//verifie que le path finisse bien par .txt
	void donne_fich_ecrivable();//verifie si le fichier du log existe, si c'est le cas, propose de le remplacer ou de changer numero
	void creerFich();//créer un fichier blanc a l'adresse du param.pathEtNomLog et renvoie une erreur si peut pas ecrire




};

#endif
