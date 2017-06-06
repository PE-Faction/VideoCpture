/*#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\video\video.hpp>
#include <iostream>
#include <string.h>
using namespace cv;
using namespace std;

int main()
{
	cv::VideoCapture vcapL;
	cv::VideoCapture vcapR;
	cv::Mat imageL;
	cv::Mat imageR;
	cv::namedWindow("output Left", CV_WINDOW_NORMAL | CV_WINDOW_KEEPRATIO);
	cv::namedWindow("output Right", CV_WINDOW_NORMAL | CV_WINDOW_KEEPRATIO);

	const std::string addressL = "http://root:drrobot@192.168.0.96:8083/mjpg/video.mjpg";
	const std::string addressR = "http://root:drrobot@192.168.0.97:8082/mjpg/video.mjpg";

	if (!vcapL.open(addressL) || !vcapR.open(addressR)) 
 //     if (!vcapL.open(0) || !vcapR.open(0)) 
{
		std::cout << "Error" << std::endl;
		system("pause");
		return -1;
	}

	int i = 0;
	char t[256];
	std::string number;
	for (;;)
	{
		if (!vcapL.read(imageL) || !vcapR.read(imageR))
		{
			std::cout << "No frame" << std::endl;
			cv::waitKey();
		}
		cv::imshow("output Left", imageL);
		cv::imshow("output Right", imageR);
		if (cv::waitKey(1) == 'a')
		{
			sprintf(t, "%d", i++);
			number = t;
			cv::imwrite("Left" + number + ".jpg", imageL);
			cv::imwrite("Right" + number + ".jpg", imageR);
			cout << "已经写入" << i << "张图片" << endl;
		}
		else if (cv::waitKey(1) == 'q')
		{
			break;
		}


	}

	return 0;
}
*/