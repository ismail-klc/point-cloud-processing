#include "RadiusOutlierFilter.h"
#include <iostream>
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
using namespace std;

int main()
{
	DepthCamera camera("camera1.txt");

	PointCloud pointCloud = camera.capture();

	RadiusOutlierFilter rof(25);
	rof.filter(pointCloud);

	PointCloudRecorder record("Rof test.txt");
	record.save(pointCloud);


	system("pause");
}