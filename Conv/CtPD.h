#include <iostream>
#include <fstream>

#include "../Erreur/ErreurConv.h"


class CartToPolDegree// class pour gérer la conversion carthesien-> Polaire (inverse pas necessaire normalement)  en DEGREES, ENTRE -180 +180 °
	//L'angle 0 EST LA VERTICALE montante, SENS TRIGO, valeur de l'angle entre 
	// ATTENTION : si veut convertir des fractions rationnelles , IL FAUT mettre au moins un des nombres de la fraction avec .0 exemple:
	// 1.0/2 et non 1/2 (sinon division entre deux entier va renvoyer un entier => 0 )
{

private:
	double r;//rayon
	double t;//angle
public:
	CartToPolDegree();
	CartToPolDegree(double x, double y);
	CartToPolDegree(const CartToPolDegree &a);
	double normalise(double a)const;//met angle entre -180 180 si besoin
	double  gR() const;
	double  gT() const;
	void Erreur(std::string mess)const;// a defaut de mieux pour linstant affiche juste dans terminal, il faudrait mettre dans LOG aussi TODO
	std::string toString()const;
};
std::ostream &operator<<(std::ostream & flux, CartToPolDegree const & v);