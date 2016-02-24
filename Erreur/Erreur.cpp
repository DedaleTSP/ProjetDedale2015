#include "Erreur.h"

using namespace std;




	//---------------constructeur----------

Erreur::Erreur(P_E_C param2)
	{
		param.aff = 1;
		param.pathEtNomLog = "~/.ARDroneFlightController/Log/LogConv.txt";// tj initialiser au cas ou

		change_log(param2.pathEtNomLog);
		change_param(param2);
	}
	//gestion du fichier log
void Erreur::trouve_bon_nom()
	{
		verif_path_txt();//inutile a priori mais ca coute pas grand chose de verifier comme on va enlever le '.txt' du nom

		int j = 1;
		string temp = param.pathEtNomLog.substr(0, param.pathEtNomLog.length() - 4) + std::to_string(j)+ ".txt";

		ifstream Flux;
		Flux.open(temp.c_str());
		while (Flux)//tant que le fichier existe deja on en cherche un autre
		{
			Flux.close();
			j++;
			temp = param.pathEtNomLog.substr(0, param.pathEtNomLog.length() - 4) + to_string(j) + ".txt";
			Flux.open(temp.c_str());
		}
		Flux.close();
		param.pathEtNomLog = temp;
		verif_path_txt();//inutile a priori mais ca coute pas grand chose de verifier
	}
void Erreur::creerFich()//créer un fichier blanc a l'adresse du param.pathEtNomLog et renvoie une erreur puis un prompt si peut pas ecrire
	{
		ofstream LOG(param.pathEtNomLog.c_str());//sans le ios::app ca va ecrire un fichier blanc
		if (!LOG)
		{
			param.pathEtNomLog = demande_info("----------------------------ERREUR----------------------->\n Impossible d'écrire dans le fichier log a l'adresse : " + param.pathEtNomLog + " \n il y a probablement un problème de droit d'ecriture sur le fichier/dossier \n<---------------------------ERREUR------------------------\n Veuillez en entrer un valide : ");
			donne_fich_ecrivable();
			return;
		}
		LOG.close();
	}
void Erreur::donne_fich_ecrivable()
	{
		while (!verif_path_txt())
		{

		}

		ifstream monFlux(param.pathEtNomLog.c_str());  //verifie si log existe deja
		if (!monFlux)//si il existe pas c'est bon
		{
			monFlux.close();
			creerFich();//on verifie quand même qu'on puisse ecrire a cet endroit
			return;
		}
		monFlux.close();
		//sinon on demande a l'utilisateur
		string rep;
		rep = demande_info("le log: " + param.pathEtNomLog + "\nexiste deja, voulez vous le remplacer? \ny=ecrire par dessus , n=trouve automatiquement un nom libre\n");
		while ((rep != "y") && (rep != "n"))
		{
			rep = demande_info("veuillez repondre par y ou n \ny=ecrire par dessus , n=trouve automatiquement un nom libre\n");
		}

		if (rep == "y")
		{
			creerFich();
			return;
		}
		trouve_bon_nom();//sinon on trouve un nom qui marche
		creerFich();
	}
bool Erreur::verif_path_txt()
{
	if (param.pathEtNomLog.length() < 4)
	{
		param.pathEtNomLog = demande_info("le chemin entre ne fini par par .txt, l'ancien chemin etait :\n" + param.pathEtNomLog + "\nVeuillez en entrer un valide:");
		return(false);
	}
	string subs = param.pathEtNomLog.substr(param.pathEtNomLog.length() - 4, param.pathEtNomLog.length());
	if (subs != ".txt")
	{
		param.pathEtNomLog = demande_info("le chemin entre ne fini par par .txt, l'ancien chemin etait :\n"+param.pathEtNomLog + "\nVeuillez en entrer un valide:");
		affiche_direct("donne_fich");
		return(false);
	}
	return true;
}
bool Erreur::change_log(string path)
	{
		param.pathEtNomLog = path;
		donne_fich_ecrivable();
		return (Log("###-------Debut Log conversion IA-> mouvements et commandes AT-------###\n Ecriture dans : " + param.pathEtNomLog, -1));
	}
bool Erreur::change_param(P_E_C nouv)
	{
		return(change_param(nouv.aff));
	}
bool Erreur::change_param(int param2)
	{
		param.aff = param2;
		return(Log("\n\nChangement parametre du log :\n" + param, -1));
	}
bool Erreur::change_param(bool aff_critique, bool aff_non_usu, bool aff_tout)
	{
		if (aff_tout)
		{
			return(change_param(2));
		}
		else if (aff_non_usu)
		{
			return(change_param(1));
		}
		else if (aff_critique)
		{
			return(change_param(0));
		}
		else
		{
			return(change_param(0));
		}
	}
P_E_C Erreur::get_param()const
{
	return(param);
}
	//--la Principale--- ecriture dans le fichier log
bool Erreur::Log(string const mess, int const priorite)
	{
		char x = '-';
		string prio(abs(priorite+1)*3 , x);
		if (priorite > param.aff)
		{

			affiche_direct("\n*********************************************************");
			affiche_direct("non logue car priorite trop basse : \n\n" + prio+mess);
			affiche_direct("*********************************************************\n");

			return false;
		}


		/*
		affiche_direct("\n*********************************************************");
		affiche_direct("dans:" + param.pathEtNomLog+"\non logue : \n\n" + prio+mess );
		affiche_direct("*********************************************************\n");
		*/


		ofstream LOG(param.pathEtNomLog.c_str(), ios::app);
		if (LOG)
		{
			LOG << prio+mess << endl;
			return true;
		}
		else
		{
			affiche_direct( "----------------------------ERREUR----------------------->\n Impossible d'ecrire dans le fichier log a l'adresse : " + param.pathEtNomLog + " \n<---------------------------ERREUR------------------------\n");
			donne_fich_ecrivable();
			return false;
		}

	}
	//Interrupt
void Erreur::interr_lethal(string mess)
{
	affiche_direct(mess);
	affiche_direct("------------------------\n---Suite a une erreur critique, le programme de Log s'arretera au prochain appui sur une touche---\n------------------------");
	system("pause");// A CHANGER POUR UNIX
	exit(1);
}
//prompt et affichage: interraction directe avec l'utilsateur
void Erreur::affiche_direct(string mess)
{
	cout << mess << endl;
}
string Erreur::demande_info(string question)
{
	affiche_direct(question);
	affiche_direct("si vous voulez quitter tapez quit ");//ATTENTION cela veut dire que quit ne sera pas une option valide pour une demande
	string res;
	cin >> res;
	if (res == "quit")
	{
		interr_lethal("l'utilisateur a demande a quitter");
		return("");
	}
	return(res);
}





