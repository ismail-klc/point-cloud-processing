#ifndef RADIUS_OUTLIER_FILTER_H
#define RADIUS_OUTLIER_FILTER_H

#include "PointCloudFilter.h"

/**
* @author Ozkan ARSLAN stechnorsk59@gmail.com
* @date : 30 Aralik 2019 Pazartesi
* @brief : Bu nokta bulutunda filtreleme yapar. Filter fonksiyonu ile nokta bulutunu alir
* ve filtrelenmis halini dondurur. PointCloudFilter sinifindan kalitim alir.
*/

#include "PointCloud.h"

class RadiusOutlierFilter : public PointCloudFilter
{
	double radius ;
public:
	RadiusOutlierFilter(int value) { radius = value; };
	void filter(PointCloud &);
};

#endif
