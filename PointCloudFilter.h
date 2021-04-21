#ifndef POINT_CLOUD_FILTER_H
#define POINT_CLOUD_FILTER_H

#include "PointCloud.h"

/**
* @author Ahmet Telceken ahmettlckn1@gmail.com
* @date  : 30 Aralik 2019 Pazartesi
* @brief : Filtreler icin abstract siniftir.
*/

class PointCloudFilter
{	
public:
	virtual void filter(PointCloud & ) = 0;
};

#endif // !POINT_CLOUD_FILTER_H