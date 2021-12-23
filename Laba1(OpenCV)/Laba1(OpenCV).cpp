#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat picture = imread("yatorogod.jpg");

    if (picture.empty()) {
        cout << "Missing picture!" << endl;
        return -1;
    }
    resize(picture , picture ,Size(), 0.5 , 0.5);

    // отображение оригинальной картинки
    imshow("Оriginal Yatoro", picture);
    waitKey(0);

    //отображение чёрно-белой версии изображения
    Mat black_and_white_picture;
    cvtColor(picture, black_and_white_picture, COLOR_RGBA2GRAY);
    imshow("Black and white Yatoro", black_and_white_picture);
    waitKey(0);

    //отображение YUV версии изображения
    Mat yuv_picture;
    cvtColor(picture, yuv_picture, COLOR_BGR2YUV);
    imshow("YUV Yatoro", yuv_picture);
    waitKey(0);

    //оторажение изображения в схеме HSV
    Mat hsv_picture;
    cvtColor(picture, hsv_picture, COLOR_BGR2HSV);
    imshow("HSV Yatoro", hsv_picture);
    waitKey(0);

    //отображение краев обьектов
    Mat edge_picture;
    Canny(picture, edge_picture, 100, 200);
    imshow("Edge Yatoro", edge_picture);
    waitKey(0);

    //отображение размытого изображения
    Mat gauss_picture;
    GaussianBlur(picture, gauss_picture, Size(15, 15), 0);
    imshow("Gauss Yatoro", gauss_picture);
    waitKey(0);


    return 0;
}
