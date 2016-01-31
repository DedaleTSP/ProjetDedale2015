
#include "ErreurConv.h"

ErreurConv::ErreurConv(P_E_C param) :Erreur(param)
{	
}
bool ErreurConv::logCommande(std::string com)
{
	return(Log("Operation loguee: commande envoyee=" + com, 2));
}
bool ErreurConv::pasProg()
{
	return(Log("Erreur::impossible de trouver le programme 'Client_UDP' dans le dossier specifie", 0));
}
bool ErreurConv::tropR()
{
	return(Log("Erreur::plus d'un  carractère '\\r' dans la commande envoyee", 0));
}
bool ErreurConv::rstC()
{

	return(Log("Operation unusuelle loguee: compteur remis a zero", 1));

}