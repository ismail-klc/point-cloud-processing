#include <iostream>
#include <Eigen/Dense>
#include "DepthCamera.h"
#include <ctime>
#include "FilterPipe.h"
#include "PointCloud.h"
#include <cstdlib>
#include "PointCloudInterface.h"
#include "RadiusOutlierFilter.h"
#include "PassThroughFilter.h"
#include "PointCloudGenerator.h"
using namespace std;

int main()
{
	PointCloudRecorder pcr("out.txt");

	// camera1
	DepthCamera cam1("camera1.txt");
	
	FilterPipe *fp1 = new FilterPipe;
	fp1->addFilter(new RadiusOutlierFilter(25));
	fp1->addFilter(new PassThroughFilter(400, 0, 400, 0,  45, -45));
	cam1.setFilterPipe(fp1);

	Eigen::Vector3d ang1;
	Eigen::Vector3d tr1;
	ang1(0) = 0, ang1(1) = 0, ang1(2) = -90;
	tr1(0) = 100, tr1(1) = 500, tr1(2) = 50;
	Transform t1;
	t1.setRotation(ang1);
	t1.setTranslation(tr1);


	cam1.setTransformRotation(ang1);
	cam1.setTransformTranslation(tr1);
	
	//camera2
	DepthCamera cam2("camera2.txt");

	FilterPipe *fp2 = new FilterPipe;
	fp2->addFilter(new RadiusOutlierFilter(25));
	fp2->addFilter(new PassThroughFilter(500, 0, 500, 0, 45, -45));
	cam2.setFilterPipe(fp2);

	Eigen::Vector3d ang2;
	Eigen::Vector3d tr2;
	ang2(0) = 0, ang2(1) = 0, ang2(2) = 90;
	tr2(0) = 550, tr2(1) = 50, tr2(2) = 50;
	Transform t2;
	t2.setRotation(ang2);
	t2.setTranslation(tr2);

	cam2.setTransformRotation(ang2);
	cam2.setTransformTranslation(tr2);

	PointCloudInterface pci;
	pci.addGenerator(&cam2);
	pci.addGenerator(&cam1);
	pci.setRecorder(&pcr);
	pci.generate();
	pci.record();

	

	system("pause");
}