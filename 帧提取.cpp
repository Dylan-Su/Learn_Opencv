#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
	VideoCapture cap("C:\\Users\\������Ϲ˵\\source\\repos\\OpencvText\\OpencvText\\output1.avi");
	if (!cap.isOpened())
		return -1;
	//����֡��������
	int frnb = cap.get(CV_CAP_PROP_FRAME_COUNT);
	cout << "֡����="<<frnb << endl;
	Mat frame;
	//��ʼ֡��
	unsigned int fIdx = 10;
	//����֡λ��
	cap.set(CV_CAP_PROP_POS_FRAMES, fIdx);
	//��ȡ֡
	cap >> frame;
	//��ʾ֡
	namedWindow("frame", CV_WINDOW_AUTOSIZE);
	imshow("frame", frame);
	waitKey(3);
	cout << "������ 0 �� " << frnb - 1 << "�����֣�����0 �ͽ���\n" << endl;
	for (;;) {
		cout << "�ڼ���֡��";
		cin >> fIdx;
		if (fIdx > 0 && fIdx < frnb) {
			cap.set(CV_CAP_PROP_POS_FRAMES, fIdx);
			cap >> frame;
			imshow("frame", frame);
			waitKey(3);
		}
		else
			return 0;
	}
	return 0;
}
