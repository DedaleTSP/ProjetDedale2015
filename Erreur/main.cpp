#include "P_C_C.h"
#include "P_E_C.h"
#include "ErreurConv.h"

using namespace std;

// ATTENTION IL FAUT COMPILER AVEC L OPTION -std=c++11 ou plus haut ( -std=c++14 ou -std=c++0x ) SOUS GCC POUR QUE CA MARCHE !
//si vosu compilez sous windows avec GCC faites attention si il a un probl�me avec std::to_string c'est probablement que vous utilisez
//Mingw qui a un bug connu a cet endroit, t�l�chargez MingW64 et utilisez le comme compilateur
void pause()
{
	system("pause");// A CHANGER pour UNIX
}


int main()
{
	cout << "Hello world!" << endl;

	ErreurConv erreur({ "C:/log/log.txt", 1 });
	pause();
	// ATTENTION IL VA FALLOIR CHANGER L'ADRESSE PAR DEFAUT DU FICHIER pour la remettre sous format unix


	erreur.logCommande("AT commande");
	erreur.rstC();
	erreur.tropR();
	erreur.pasProg();

	erreur.change_log( "C:/log/log.tx");
	pause();
	erreur.change_param(2);
	erreur.tropR();
	erreur.logCommande("AT commande");
	erreur.rstC();
	erreur.pasProg();

	pause();
	return 0;
}

