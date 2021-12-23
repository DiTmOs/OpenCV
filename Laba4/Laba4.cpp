#include <iostream>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/stitching.hpp"
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
int main()
{
	vector<Mat> pictures;
	Stitcher::Mode mode = Stitcher::PANORAMA;
	Mat picture1 = imread("panda1.jpg");
	Mat picture2 = imread("panda2.jpg");
	Mat picture3 = imread("panda3.jpg");
	if (picture1.empty() || picture2.empty() || picture3.empty())
	{
		cout << "No picture!"<< endl;
		return -1;
	}
	pictures.push_back(picture1);
	pictures.push_back(picture2);
	pictures.push_back(picture3);
	Mat panorama;
	Ptr<Stitcher> stit = Stitcher::create(mode);

	Stitcher::Status stat = stit->stitch(pictures, panorama);

	if (stat != Stitcher::OK)
	{
		cout << "Error!" << endl;
		return -1;
	}
	resize(panorama, panorama, Size(), 0.5, 0.5);
	imwrite("panorama.jpg", panorama);
	imshow("Result", panorama);
	waitKey(0);
	return 0;
}