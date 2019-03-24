#pragma once
#ifndef __FACEALIGN_H__
#define __FACEALIGN_H__

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "net.h"
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;
/* ��ͨ��MTCNN�õ����������5�������ͼƬ����
�ʼ�����points��
0,5 ���� 1,6 ����
2,7 ���� 3,8 ��� 4,9 �ҿ�
*/
class FaceAlign {

public:
	FaceAlign();
	~FaceAlign();
	pair<cv::Mat, string> align(cv::Mat& img, const vector<float>& landmarks, int desired_size = 160, float padding = 0.1);	// ���ض����ͼ������Ӧ��λ����Ϣ

private:
	string getPos(const vector<float>& points); // �����ж����������������м�����points[0] points[1] points[2] ֮��Ĳ�ı�����������
	vector<float> list2colmatrix(const vector<pair<float, float>>& pts_list); // ����ת��
	pair<cv::Mat, cv::Mat> find_tfrom_between_shapes(const vector<float>& from_shape, const vector<float>& to_shape);
};

#endif