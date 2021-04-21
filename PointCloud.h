#ifndef POINT_CLOUD_H
#define POINT_CLOUD_H

#include "Point.h"
#include <list>

using namespace std;
/**
* @author Ahmet Telceken ahmettlckn1@gmail.com
* @date  : 30 Aralik 2019 Pazartesi
* @brief : Sahip oldugu noktalari,  bir Point listesinde tutar. 
*/

class PointCloud
{
private:
	list <Point> points;
public:
	PointCloud() {}
	list <Point> getPoints() const;
	void setPoints(list<Point> p);
	int getPointNumber() { return points.size(); }
	PointCloud& operator +(PointCloud& );
	PointCloud& operator =(const PointCloud& );


};

#endif