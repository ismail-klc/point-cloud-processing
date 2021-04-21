#include "PassThroughFilter.h"
#include <iostream>



PassThroughFilter::PassThroughFilter(double ux, double lx, double uy, double ly, double uz, double lz)
{
	/**
	* @brief : Alinan upper ve lower degerlerini degiskenlere atar.
	* @param ux: x in upper limiti
	* @param uy: y in upper limiti
	* @param uz: z in upper limiti
	* @param lx: x in lower limiti
	* @param ly: y in lower limiti
	* @param lz: z in lower limiti
	*/

	upperLimitX = ux;
	lowerLimitX = lx;
	upperLimitY = uy;
	lowerLimitY = ly;
	upperLimitZ = uz;
	lowerLimitZ = lz;
}

void PassThroughFilter::filter(PointCloud &p)
{
	/**
	* @brief : Nokta bulutunu filtreler.
	* @param &p: Nokta bulutudur
	*/

	list<Point> points = p.getPoints();
	auto it = points.begin();

	while ( it != points.end())
	{
		if ( (*it).getX() < lowerLimitX || (*it).getX() > upperLimitX || (*it).getY() < lowerLimitY || (*it).getY() > upperLimitY
			|| (*it).getZ() < lowerLimitZ || (*it).getZ() > upperLimitZ)
		{
			
			it = points.erase(it);
		}
		else
			it++;
	}
	p.setPoints(points);
}


