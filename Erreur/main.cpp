#include "P_C_C.h"
#include "P_E_C.h"
#include "ErreurConv.h"

using namespace std;


void pause()
{
	system("pause");// A CHANGER pour UNIX
}


int main()
{
	cout << "Hello world!" << endl;

	ErreurConv erreur({ "D:\\Dedale_Test_Log\\log.txt", 1 });
	pause();
	// ATTENTION IL VA FALLOIR CHANGER L'ADRESSE PAR DEFAUT DU FICHIER pour la remettre sous format unix (decommenter)


	erreur.logCommande("AT commande");
	erreur.rstC();
	erreur.tropR();
	erreur.pasProg();

	pause();
	erreur.change_param(2);
	erreur.tropR();
	erreur.logCommande("AT commande");
	erreur.rstC();
	erreur.pasProg();

	pause();
	return 0;
}

