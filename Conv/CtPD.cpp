
#include "CtPD.h";

using namespace std;




const double pi = 3.1415926535897;

double  CartToPolDegree::gR() const
{
	return(r);
}
double  CartToPolDegree::gT() const
{
	return(t);
}
void CartToPolDegree::Erreur(string mess)const
{
	cout << "ERREUR CartToPolDegree: " + mess << endl;
	system("pause");
	exit(1);
}
string CartToPolDegree::toString()const
{
	return ("(r,theta)=(" + to_string(gR()) + "," + to_string(gT()) + ")");
}
CartToPolDegree::CartToPolDegree()
{
	r = 0;
	t = 0;
}
CartToPolDegree::CartToPolDegree(const CartToPolDegree &a)
{
	r = a.gR();
	t = a.gT();
}
CartToPolDegree::CartToPolDegree(double x, double y)
{

	r = sqrt(x*x + y*y);
	double& xa = y;//reference car c'est y que je vais traiter comme x comem c'est pi/2-theta sinon
	double& ya = x;
	if (xa == 0)
	{
		if (ya == 0)
		{
			Erreur(" PAS de conversion en polaire possible avec x=y=0");//utiliser le constructeur vide si sait pas quoi mettre mais pas 0,0
		}
		else if (ya > 0)
		{
			t = (-90);
		}
		else
		{
			t = 90;
		}
		return;
	}
	double ta = ya / abs(xa);

	//cout << endl<<" xa=" + to_string(xa)+" ya=" + to_string(ya)  +" ta=" + to_string(ta) << endl;

	if (xa > 0)
	{
		t = normalise(-atan(ta)*180/pi);
	}
	else if (xa < 0)
	{
		t = normalise(atan(ta) * 180 / pi - 180);
	}
	return;
}

double CartToPolDegree::normalise(double a)const
{

	if (a>180)
		return(-180+fmod(abs(a), 180));//  -180+ a%180
	else if (a < -180)
		return(180 - fmod(abs(a), 180));//  180- a%180
	else
		return(a);
}

std::ostream &operator<<(std::ostream & flux, CartToPolDegree const & v)
{
	std::string mess = v.toString();
	flux << mess << std::endl;
	return flux;
}

