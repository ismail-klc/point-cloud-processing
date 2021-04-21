#ifndef POINT_CLOUD_GENERATOR_H
#define POINT_CLOUD_GENERATOR_H

#include "Transform.h"
#include "FilterPipe.h"
#include "PointCloud.h"

/**
* @author Yunus Emre Ozen emreozen1235@gmail.com
* @date  : 30 Aralik 2019 Pazartesi
* @brief : Dosyadan okuma yapmak icin kullanilacak abstract bir siniftir.
*/

class PointCloudGenerator
{
protected:
	Transform transform;
	FilterPipe *filterPipe;
public:
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
	void setFilterPipe(FilterPipe*);
};

#endif // !POINT_CLOUD_GENERATOR_H