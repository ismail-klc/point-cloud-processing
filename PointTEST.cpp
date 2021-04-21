#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	Point p1, p2;

	p1.setX(4);
	p1.setY(7);
	p1.setZ(8);

	p2.setX(2);
	p2.setY(6);
	p2.setZ(9);

	cout << (p1 == p2) << endl;
	cout << p1.distance(p2);



	system("pause");
}