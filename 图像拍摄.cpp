
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
	//打开编号为0的摄像头
	VideoCapture cap(0);
	//打开失败就结束程序
	if (!cap.isOpened())
	{
		cout << "无法打开摄像头" << endl;
		return -1;
	}
	char const* windowName = "Webcam Feed";
	//保存图形文件的文件名
	char filename[50];
	//文件名序列号起始
	int n = 0;
	//显示摄像头内容的窗口
	namedWindow(windowName, CV_WINDOW_AUTOSIZE);
	while (1) {
		Mat frame;
		//从摄像头读取帧（frame）
		bool bSuccess = cap.read(frame);
		//检查是否读取成功
		if (!bSuccess)
		{
			cout << "无法从摄像头读取帧" << endl;
			break;
		}
		//显示读取的帧
		imshow(windowName, frame);
		//等待10毫秒是否按键
		switch ((10))
		{
         //‘Esc’键被按下
		case 27:
			//结束程序
			return 0;
			break;
			//‘Enter’键被按下
		case 13:
			sprintf_s(filename, "C:\\VideoFramen%d.jpg", n++);
			imwrite(filename, frame);
			break;
		}
	}
	return 0;
}