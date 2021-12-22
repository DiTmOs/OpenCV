#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    Mat im_rgb = imread("yatorogod.jpg");

    if (im_rgb.empty()) {
        cout << "Error" << endl;
        return -1;
    }
    resize(im_rgb, im_rgb ,Size(), 0.5 , 0.5);
    imshow("original", im_rgb);
    waitKey(0);

    Mat im_black_and_white;
    cvtColor(im_rgb, im_black_and_white, COLOR_RGBA2GRAY);
    imshow("black_and_white", im_black_and_white);
    waitKey(0);

    Mat im_clr;
    cvtColor(im_rgb, im_clr, COLOR_BGR2YUV);
    imshow("YUV", im_clr);
    waitKey(0);

    Mat im_canny;
    Canny(im_rgb, im_canny, 100, 200, 3);
    imshow("Canny", im_canny);
    waitKey(0);

    Mat im_gauss;
    GaussianBlur(im_rgb, im_gauss, Size(7, 7), 0);
    imshow("Gauss", im_gauss);
    waitKey(0);

    Mat im_hsv;
    cvtColor(im_rgb, im_hsv, COLOR_BGR2HSV);
    imshow("HSV", im_hsv);
    waitKey(0);

    return 0;
}
