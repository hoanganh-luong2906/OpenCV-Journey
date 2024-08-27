#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	string imgLink;
	cout << "Enter the image link: ";
	getline(cin, imgLink);
	Mat img = imread(imgLink);
	while (img.empty()) {
		cout << "Img not found, please enter another URL: ";

		getline(cin, imgLink);
		imgLink = "@" + imgLink;
		if (imgLink == "exit") {
			cout << "Exit program";
			return 0;
		}
		img = imread(imgLink);
	}

	string windowName = "Image";
	namedWindow(windowName, WINDOW_NORMAL);
	imshow(windowName, img);

	waitKey(0);
	destroyWindow(windowName);
	return 0;

}