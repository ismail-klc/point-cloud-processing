#include "PointCloud.h"
#include <iostream>
using namespace std;

/* @brief :  Sahip olduðu noktalari, dinamik olarak yaratilan bir Point dizisinde tutar.
*/


list<Point> PointCloud::getPoints()const
{
	/**
	* @brief :  Point dizisini dondurur.
	* @see main() : fonksiyonun hangi amacla cagrildigini inceleyiniz.
	* @return : Nokta bulutunu dondurur.
	*/
	return points;
}

void PointCloud::setPoints(list<Point> p)
{
	/**
	* @brief :  Bir nokta bulutundaki degerleri diger nokta bulutuna aktarir.
	* @param p : Esitlenecek noktalardir.
	*/
	points = p;
}

PointCloud& PointCloud::operator+(PointCloud& p)
{
	/**
	* @brief :  Iki nokta bulutunu toplayip tek bir nokta bulutu haline getirir.
	* @param &p : Nokta bulutudur.
	* @return : Toplanan nokta bulut degerlerini dondurur.
	*/

	auto p1 = this->getPoints();
	auto p2 = p.getPoints();
	list<Point>temp;

	for (auto it = p1.begin(); it != p1.end(); it++)
	{
		temp.push_back(*it);
	}

	for (auto it = p2.begin(); it != p2.end(); it++)
	{
		temp.push_back(*it);
	}

	PointCloud *npc = new PointCloud();
	npc->setPoints(temp);

	return *npc;
}
PointCloud& PointCloud::operator =(const PointCloud& p)
{
	/**
	* @brief :  Esitligin sagindaki nokta bulutunu solundakine esitler.
	* @param &p : Nokta bulutudur.
	* @return : Esitlenen nokta bulutunu dondurur.
	*/

	list <Point>point = p.getPoints();
	setPoints(point);

	return *this;
}

