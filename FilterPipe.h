#ifndef FILTER_PIPE_H
#define FILTER_PIPE_H

#include "PointCloudFilter.h"
#include <vector>

/**
* @author Ozkan ARSLAN stechnorsk59@gmail.com
* @date  : 30 Aralik 2019 Pazartesi
* @brief : Birden fazla filtreden gecmesi gereken nokta bulutunun filtreleme islemini yapacak
siniftir.
*/

class FilterPipe
{
private:
	vector<PointCloudFilter*> filters;
public:
	FilterPipe() {}
	void addFilter( PointCloudFilter * filter);
	int getFilterNums() { return filters.size(); }
	void filterOut(PointCloud & pc);
};

#endif // !FILTER_PIPE_H