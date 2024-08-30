#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* agrv[])
{
	string imagePath;
	cout << "Enter the path of the image: ";
	getline(cin, imagePath);

	Mat image = imread(imagePath);

	while (image.empty())
	{
		cout << "Image not found. Please enter another path: ";
		getline(cin, imagePath);

		Mat image = imread(imagePath);
	}

	// Increase the brightness by 100
	Mat imageBrightnessHigh100;
	image.convertTo(imageBrightnessHigh100, -1, 1, 100);

	// Increase the contrast by 2
	Mat imageConstrastDouble;
	image.convertTo(imageConstrastDouble, -1, 2, 0);

	// Equalize image's histogram
	cvtColor(image, image, COLOR_BGR2GRAY); //Chang image's color to grayscale

	Mat imageHistEqualized;
	equalizeHist(image, imageHistEqualized);


	string windowNameOriginalImage = "Original Image";
	string windowNameBrightnessHigh100 = "Brightness + 100";
	string windowNameContrastDouble = "Contrast Double";
	string windowNameHistEqualized = "Histogram Equalized";

	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	namedWindow(windowNameContrastDouble, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessHigh100, WINDOW_NORMAL);
	namedWindow(windowNameHistEqualized, WINDOW_NORMAL);

	imshow(windowNameOriginalImage, image);
	imshow(windowNameContrastDouble, imageConstrastDouble);
	imshow(windowNameBrightnessHigh100, imageBrightnessHigh100);
	imshow(windowNameHistEqualized, imageHistEqualized);
	
	waitKey(0);
	destroyAllWindows();
	return 0;
}