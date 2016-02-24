#include <iostream>
#include <fstream>
#include <math.h>




using namespace std;

/*
#include "CtPD.h";

void test(double x, double y)
{
	CartToPolDegree lala;

	lala = CartToPolDegree(x, y);
	cout << "("+to_string(x) + "," + to_string(y) +")=> " << lala;
}
int main()
{
    cout << "Hello world!" << endl;

	CartToPolDegree lala;
	
	lala = CartToPolDegree( 1, 0 );// -90°
	cout << "( 1, 0 )=>" << lala;
	lala = CartToPolDegree(-1, 0);// 90°
	cout  <<"(-1, 0)=>" << lala;
	lala = CartToPolDegree(0, 1);// 0°
	cout  << "(0, 1)=>" << lala;

	test(-0.00001, -0.9999);// ~180°
	test(0.00001, -0.9999);// ~ - 180°
	

	test(sqrt(2)/ 2, sqrt(2) / 2);// -45
	test(-sqrt(2) / 2, sqrt(2) / 2);// 45
	test(sqrt(3)/2, 1.0/2);// -60
	test(sqrt(3)/2 , -1.0 / 2);// -(90+60)
	

	system("pause");
    return 0;
}

*/


#include "../Erreur/ErreurConv.h"

void test(int a)
{
	int tab[2][15] = { { -100, -75, -50, -25, -20, -10, -5,0, 5, 10, 20, 25, 50, 75, 100 }, { -1082130432, -1086324736, -1090519040, -1098907648, -1102263091, -1110651699, -1119040307,0, 1028443341, 1036831949, 1045220557, 1048576000, 1056964608, 1061158912, 1065353216 } };
	if (a == 0)
	{
		//return 0;
	}

	int i = 0;
	int j = 14;
	while ((i < j) && (i < 14) && ( (tab[0][i + 1] <= a) || (tab[0][j - 1] >= a)))
	{
		if (tab[0][i + 1] <= a)
			i++;
		if (tab[0][j - 1] >= a)
			j--;
	}
	cout << "i,j=" << i << "," << j << "tab i,j " << tab[0][i] << "," << tab[0][j] ;
	if (abs(tab[0][i] - a) <= abs(tab[0][j] - a))
		cout << "=>> res=" << tab[0][i] << endl;
	else
		cout << "=>> res=" << tab[0][j] << endl;
}
int main()
{
	cout << "Hello world!" << endl;

	int tab[2][14] = { { -100, -75, -50, -25, -20, -10, -5, 5, 10, 20, 25, 50, 75, 100 }, { -1082130432, -1086324736, -1090519040, -1098907648, -1102263091, -1110651699, -1119040307, 1028443341, 1036831949, 1045220557, 1048576000, 1056964608, 1061158912, 1065353216 } };
	
	for (int a = -101; a <150; a+=10)
	{
		cout << a<<" => ";
		test(a);
	}
	

	system("pause");
	return 0;
}