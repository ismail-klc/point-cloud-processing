#ifndef PASS_THROUGH_FILTER_H
#define PASS_THROUGH_FILTER_H

#include "PointCloud.h"
#include "PointCloudFilter.h"

/**
* @author Yunus Emre Ozen emreozen1235@gmail.com
* @date :6 Aralik 2019 Cuma
* @brief : Bu nokta bulutunda filtreleme yapar. Filter fonksiyonu ile nokta bulutunu alir
* ve filtrelenmis halini dondurur. PointCloudFilter sinifindan kalitim alir.
*/

class PassThroughFilter : public PointCloudFilter
{
	double upperLimitX;
	double lowerLimitX;
	double upperLimitY;
	double lowerLimitY;
	double upperLimitZ;
	double lowerLimitZ;
public:
	PassThroughFilter() {}
	PassThroughFilter(double, double, double, double, double, double);
	void filter(PointCloud &);
};

#endif // !PASS_THROUGH_FILTER_H