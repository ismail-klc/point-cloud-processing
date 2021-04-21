#include "RadiusOutlierFilter.h"
#include <iostream>


void RadiusOutlierFilter::filter(PointCloud &p)
{
	/**
	* @brief : Nokta nulutundaki her bir nokta icin tek tek islem yapilir.
	* @param &p : Filtereme yapilicak nokta bulutudur.
	*/

	auto points = p.getPoints();
	auto it = points.begin();

	while ( it != points.end())
	{
		int count = 0;

		auto it2 = points.begin();
		while ( it2 != points.end())
		{
			if (((*it2).distance(*it) < radius) && !(it == it2))
			{
				count++;
				break;
			}

			if (it2 != points.end())
				it2++;
		}
		if (!count)
		{
			it = points.erase(it);
		}
		if (count)
			it++;
	}
	p.setPoints(points);
}