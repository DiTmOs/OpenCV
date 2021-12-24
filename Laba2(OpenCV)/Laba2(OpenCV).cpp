#include <iostream>
#include <algorithm>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void Grad(const Mat& OrigPicture)
{
    Mat GradX = OrigPicture.clone();
    Mat GradY = OrigPicture.clone();
    
    for (int row = 0; row < OrigPicture.rows - 1; ++row)
    {
        for (int column = 0; column < OrigPicture.cols - 1; ++column)
        {
            GradX.at<Vec3b>(Point(row, column)) = (OrigPicture.at<Vec3b>(Point(row, column + 1)) - OrigPicture.at<Vec3b>(Point(row, column)));
            GradY.at<Vec3b>(Point(row, column)) = (OrigPicture.at<Vec3b>(Point(row + 1, column )) - OrigPicture.at<Vec3b>(Point(row, column)));
        }
    }
    Mat GradXY = OrigPicture.clone();
    GradXY = GradX + GradY;

    imshow("GradX", GradX);
    waitKey(0);

    imshow("GradY", GradY);
    waitKey(0);

    imshow("GradXY",GradXY);
    waitKey(0);
}
void Blur(Mat& OrigPicture)
{
    int BlurKoef = 3;
    int width = OrigPicture.cols;
    int height = OrigPicture.rows;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int pixels = 0;
            int Red = 0, Green = 0, Blue = 0;
            for (int y = i - BlurKoef; y <= i + BlurKoef; ++y)
            {
                int YY = min(height - 1, max(0, y));
                for (int x = j - BlurKoef; x <= j - BlurKoef; ++x)
                {
                    int XX = min(width - 1, max(0, x));
                    Vec3b color = OrigPicture.at<Vec3b>(Point(XX, YY));
                    Red += color[2];
                    Green += color[1];
                    Blue += color[0];
                    ++pixels;
                }
            }
            if (pixels != 0)
            {
                Red = (Red / pixels) & 0xFF;
                Green = (Green / pixels) & 0xFF;
                Blue = (Blue / pixels) & 0xFF;
            }
            Vec3b color(Blue , Green, Red);
            OrigPicture.at<Vec3b>(Point(j, i)) = color;

        }

    }
    imshow("Blur", OrigPicture);
    waitKey(0);

}
int main()
{
    Mat OrigPicture = imread("Collaps.jpg");
    if (!OrigPicture.data)
    {
        cout << "No picture!" << endl;
        return -1;
    }
    Mat BlurPicture = OrigPicture.clone();
    Blur(BlurPicture);
    Grad(OrigPicture);
    return 0;
}
