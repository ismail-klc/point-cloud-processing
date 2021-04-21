#include "FilterPipe.h"

void FilterPipe::addFilter(PointCloudFilter * filter)
{
	/**
	* @brief :  Filters listesine aldigi filtreyi ekler.
	* @param *filter : Eklenecek filtredir.
	*/

	filters.push_back(filter);
}

void FilterPipe::filterOut(PointCloud & pc)
{/**
	* @brief :  Aldigi nokta bulutunu filters listesindeki filtrelerden gecirir.
	* @param &pc : Nokta bulutudur.
	*/

	for (size_t i = 0; i < filters.size(); i++)
	{
		filters[i]->filter(pc);
	}
}


