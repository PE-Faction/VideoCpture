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

	const std::string addressL = "http://root:drrobot@192.168.0.96:8083/mjpg/video.mjpg";
	const std::string addressR = "http://root:drrobot@192.168.0.97:8082/mjpg/video.mjpg";

//	if (!vcapL.open(addressL) || !vcapR.open(addressR))
     if (!vcapL.open(0) || !vcapR.open(0)) 
	{
		std::cout << "Error" << std::endl;
		system("pause");
		return -1;
	}
   //��ȡ֡�Ŀ��
   int w = static_cast<int>(vcapL.get(CV_CAP_PROP_FRAME_WIDTH));
   int h = static_cast<int>(vcapL.get(CV_CAP_PROP_FRAME_HEIGHT));
   Size  s(w, h);

   //��ȡ֡��
   double r = vcapL.get(CV_CAP_PROP_FPS);

   VideoWriter writeL;
   VideoWriter writeR;

    //�ڶ�������˵��������Ƶ�ı�����ʽ
//   writeL.open("L1.avi",-1,r,s,true);
 //  writeR.open("R1.avi",-1,r,s,true);

   writeL.open("L1.avi", -1, 25.0, s, true);
   writeR.open("R1.avi", -1, 25.0, s, true);
  
//	 writeL.open("L1.avi", CV_FOURCC('X', 'V', 'I', 'D'), r, s, true);
//     writeR.open("R1.avi", CV_FOURCC('X', 'V', 'I', 'D'), r, s, true);



   bool	stop = false;
   Mat frameL;
   Mat frameR;
   int temp = 0;
   int cau = 0;

   int a = 0;
   cout << "�Ƿ�ʼ¼�ƣ�";
   cin >> a;
   if (a == 1)
   {

	   cout << "�Ѿ���ʼ¼ȡ��Ƶ" << endl;
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
		   cout << "��¼���"<<cau<<"֡"<< endl;
	   }

	   if (waitKey(1) == 'q')
	   {
		   cout << "¼ȡ����" << endl;
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
*/