#include "P_C_C.h"
#include "P_E_C.h"
#include "ErreurConv.h"

using namespace std;

// ATTENTION IL FAUT COMPILER AVEC L OPTION -std=c++11 ou plus haut ( -std=c++14 ou -std=c++0x ) SOUS GCC POUR QUE CA MARCHE !
//si vosu compilez sous windows avec GCC faites attention si il a un probl�me avec std::to_string c'est probablement que vous utilisez
//Mingw qui a un bug connu a cet endroit, t�l�chargez MingW64 et utilisez le comme compilateur
void pause()
{
	system("pause");// A CHANGER pour UNIX par (�a devrait faire l'affaire)
	//system("read"); 
}


int main()
{
	cout << "Hello world!" << endl;


	//pour UNIX: 
	//	ErreurConv erreur({ "~/log/log.txt", 1 }); 
	//par exemple
	ErreurConv erreur({ "C:/log/log.txt", 1 });
	pause();

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

