#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

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
	Mat equalizedImage;
	cvtColor(image, equalizedImage, COLOR_BGR2YCrCb); //Chang image's color to YCrCb color format

	vector<Mat> vectorChannels;
	split(equalizedImage, vectorChannels);
	equalizeHist(vectorChannels[0], vectorChannels[0]); //Equalize the histogram of the Y channel
	merge(vectorChannels, equalizedImage); //Merge 3 channels including the modified Y channel
	cvtColor(equalizedImage, equalizedImage, COLOR_YCrCb2BGR); //Convert the image back to BGR color format


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
	imshow(windowNameHistEqualized, equalizedImage);
	
	waitKey(0);
	destroyAllWindows();
	return 0;
}