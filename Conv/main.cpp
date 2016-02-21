#include <iostream>
#include <fstream>
#include <math.h>

#include "CtPD.h";

using namespace std;

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
	/*

	test(sqrt(2)/ 2, sqrt(2) / 2);// -45
	test(-sqrt(2) / 2, sqrt(2) / 2);// 45
	test(sqrt(3)/2, 1.0/2);// -60
	test(sqrt(3)/2 , -1.0 / 2);// -(90+60)
	*/

	system("pause");
    return 0;
}

