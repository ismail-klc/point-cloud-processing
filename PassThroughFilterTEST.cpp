#include "PassThroughFilter.h"
#include <iostream>
#include "PointCloudRecorder.h"
#include "RadiusOutlierFilter.h"
#include "DepthCamera.h"
using namespace std;

int main()
{
	DepthCamera camera("camera1.txt");
	
	PointCloud pointCloud = camera.capture();

	PassThroughFilter ptf(400,0,400,0,45,-45);
	ptf.filter(pointCloud);

	PointCloudRecorder record("pfttest.txt");
	record.save(pointCloud);



	system("pause");
}