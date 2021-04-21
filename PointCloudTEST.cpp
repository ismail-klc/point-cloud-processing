#include "PointCloud.h"
#include <iostream>
using namespace std;

int main()
{
	PointCloud pc1, pc2;

	list<Point>points1;
	list<Point>points2;

	

	for (int i = 0; i < 3; i++)
	{
		Point p1, p2;

		p1.setX(i + 3);		p2.setX(i + 1);
		p1.setY(i + 2);		p2.setY(i + 2);
		p1.setZ(i + 1);		p2.setZ(i + 3);

		points1.push_back(p1);
		points2.push_back(p2);
	}

	pc1.setPoints(points1);
	pc2.setPoints(points2);

	list<Point>points3 = pc1.getPoints();
	list<Point>points4 = pc2.getPoints();

	auto iter1 = points3.begin();
	auto iter2 = points4.begin();

	for (iter1;iter1!=points3.end();iter1++)
	{
		cout << (*iter1).getX() << " " << (*iter1).getY() << " " << (*iter1).getZ() << endl;
	}

	PointCloud pc;
	pc = pc1 + pc2;

	auto points = pc.getPoints();
	auto iter = points.begin();

	cout << endl << "Toplama test" << endl;
	for (iter; iter != points.end(); iter++)
	{
		cout << (*iter).getX() << " " << (*iter).getY() << " " << (*iter).getZ() << endl;
	}

	system("pause");
}