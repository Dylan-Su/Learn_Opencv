
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
string intToString(int number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}
int main()
{
	//�򿪱��Ϊ0������ͷ
	VideoCapture cap(0);
	//��ʧ�ܾͽ�������
	if (!cap.isOpened())
	{
		cout << "�޷�������ͷ" << endl;
		return -1;
	}
	char const* windowName = "Webcam Feed";
	//����ͼ���ļ����ļ���
	char filename[50];
	//�ļ������к���ʼ
	int n = 0;
	//��ʾ����ͷ���ݵĴ���
	namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	while (1) {
		Mat frame;
		//������ͷ��ȡ֡��frame��
		bool bSuccess = cap.read(frame);
		//����Ƿ��ȡ�ɹ�
		if (!bSuccess)
		{
			cout << "�޷�������ͷ��ȡ֡" << endl;
			break;
		}
		//��ʾ��ȡ��֡
		imshow(windowName, frame);
		//�ȴ�10�����Ƿ񰴼�
		switch ((10))
		{
         //��Esc����������
		case 27:
			//��������
			return 0;
			break;
			//��Enter����������
		case 13:
			sprintf_s(filename, "C:\\VideoFramen%d.jpg", n++);
			imwrite(filename, frame);
			break;
		}
	}
	return 0;
}