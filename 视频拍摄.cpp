/*
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cout << "�޷���������ͷ" << endl;
		return -2;
	}
	//ȡ��ͼ��֡�Ĵ�С
	Size S = Size((int)cap.get(CV_CAP_PROP_FRAME_HEIGHT),
		(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	//��������ʼ����Ƶ�洢����
	VideoWriter put("C:\\Users\\������Ϲ˵\\source\\repos\\OpencvText\\OpencvText\\output1.avi", CV_FOURCC('M', 'P', '4', '2'), 30, S);
	
	if (!put.isOpened())
	{
		cout << "�޷�������Ƶ�ļ�" << endl;
		return -1;

	}
	namedWindow("Video");
	//��ʼ����
	while (char(waitKey(1)) != 'q' && cap.isOpened())
	{
		Mat frame;
		cap >> frame;
		//�������ͷ�Ƿ��������
		if (frame.empty())
		{
			break;
		}
		imshow("Video", frame);
		put << frame;
	}
	return 0;
}*/