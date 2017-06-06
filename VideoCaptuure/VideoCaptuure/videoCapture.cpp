#include <opencv2\core\core.hpp>
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

	const std::string addressL = "http://root:drrobot@192.168.0.96:8083/mjpg/video.mjpg";
	const std::string addressR = "http://root:drrobot@192.168.0.97:8082/mjpg/video.mjpg";

//	if (!vcapL.open(addressL) || !vcapR.open(addressR))
     if (!vcapL.open(0) || !vcapR.open(0)) 
	{
		std::cout << "Error" << std::endl;
		system("pause");
		return -1;
	}
   //获取帧的宽高
   int w = static_cast<int>(vcapL.get(CV_CAP_PROP_FRAME_WIDTH));
   int h = static_cast<int>(vcapL.get(CV_CAP_PROP_FRAME_HEIGHT));
   Size  s(w, h);

   //获取帧率
   double r = vcapL.get(CV_CAP_PROP_FPS);

   VideoWriter writeL;
   VideoWriter writeR;

    //第二个参数说明的是视频的编码形式
   /*
      CV_FOURCC('P', 'I', 'M', '1') = MPEG-1 codec
      CV_FOURCC('M', 'J', 'P', 'G') = motion-jpeg codec
      CV_FOURCC('M', 'P', '4', '2') = MPEG-4.2 codec 
      CV_FOURCC('D', 'I', 'V', '3') = MPEG-4.3 codec 
      CV_FOURCC('D', 'I', 'V', 'X') = MPEG-4 codec 
      CV_FOURCC('U', '2', '6', '3') = H263 codec 
      CV_FOURCC('I', '2', '6', '3') = H263I codec 
      CV_FOURCC('F', 'L', 'V', '1') = FLV1 codec
   */
//   writeL.open("L1.avi",-1,r,s,true);
 //  writeR.open("R1.avi",-1,r,s,true);

 //  writeL.open("L1.avi", -1, 25.0, s, true);
 //  writeR.open("R1.avi", -1, 25.0, s, true);
  
	 writeL.open("L1.avi",  CV_FOURCC('M', 'J', 'P', 'G'),25.0, s, true);
     writeR.open("R1.avi",  CV_FOURCC('M', 'J', 'P', 'G'),25.0, s, true);



   bool	stop = false;
   Mat frameL;
   Mat frameR;
   int temp = 0;
   int cau = 0;

   int a = 0;
   cout << "是否开始录制：";
   cin >> a;
   if (a == 1)
   {

	   cout << "已经开始录取视频" << endl;
	   temp = 1;
   }


   while (!stop)
   {
	   if (!vcapL.read(frameL) || !vcapR.read(frameR))
		  break;

	   imshow("leftFrame", frameL);
	   imshow("rightFrame", frameR);
	   if (temp == 1)
	   {
		   writeL.write(frameL);
		   writeR.write(frameR);
		   cau++;
		   cout << "已录入第"<<cau<<"帧"<< endl;
	   }

	   if (waitKey(1) == 'q')
	   {
		   cout << "录取结束" << endl;
		   stop = true;
	   }
	   if (cv::waitKey(10) > 0)
		   stop = true;
   }



   vcapL.release();
   vcapR.release();
   writeL.release();
   writeR.release();
	return 0;
}
