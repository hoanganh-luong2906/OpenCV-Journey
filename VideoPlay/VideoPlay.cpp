#include "VideoPlay.h"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	string videoPath; 
	cout << "Please enter the video path: ";
	getline(cin, videoPath);

	VideoCapture cap(videoPath);
	while (!cap.isOpened())
	{
		cout << "Error opening video stream or file" << endl;
		cout << "Please enter another video path: ";
		getline(cin, videoPath);
		cap.open(videoPath);
	};
	double fps = cap.get(CAP_PROP_FPS);
	cout << "Video is displayed in " << fixed << setprecision(2) << fps << " FPS" << endl;

	string windowName = "Video Player";
	namedWindow(windowName, WINDOW_NORMAL);
	while (true)
	{
		Mat frames;
		bool isSuccess = cap.read(frames);
		if (!isSuccess)
		{
			cout << "Video ended" << endl;
			break;
		}

		imshow(windowName, frames);

		if(waitKey(10) == 27)
		{
			cout << "Esc is pressed, stopping the video" << endl;
			break;
		}
	}

	return 0;
}





















