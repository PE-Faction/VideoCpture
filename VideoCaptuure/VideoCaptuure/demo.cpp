/*#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\video\video.hpp>
#include <iostream>
#include <string.h>

using namespace cv;
using namespace std;

int main()
{
	cvNamedWindow("avi");

	CvCapture* capture = cvCreateFileCapture("R1.avi");

	IplImage* frame;

	while (1)

	{

		frame = cvQueryFrame(capture);

		if (!frame)   break;

		cvShowImage("avi", frame);

		char   c = cvWaitKey(33);



		if (c == 27)   break;

	}

	cvReleaseCapture(&capture);

	cvDestroyWindow("avi");



	return 0;
}*/