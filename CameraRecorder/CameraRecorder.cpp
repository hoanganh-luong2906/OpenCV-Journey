#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cout << "Can not open camera" << endl;
		cin.get();
		return -1;
	}

	double dWidth	= static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
	double dHeight	= static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

	Size frames_size(dWidth, dHeight);
	int frames_per_second = 10;

	VideoWriter oVideoWriter(
			"D:/Recorded/MyVideo.mp4", 
			VideoWriter::fourcc('M', 'J', 'P', 'G'), 
			frames_per_second, 
			frames_size, 
			true
		);
	if (!oVideoWriter.isOpened())
	{
		cout << "Failed to save the video" << endl;
		cin.get();
		return -1;
	}


	string window_name = "My Camera Feed";
	namedWindow(window_name, WINDOW_NORMAL);

	while (true)
	{
		Mat frame;
		bool isSuccess = cap.read(frame);

		if (!isSuccess)
		{
			cout << "Camera disconnected" << endl;
			cin.get();
			break;
		}

		imshow(window_name, frame);

		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}
	}

	oVideoWriter.release();

	return 0;
}























