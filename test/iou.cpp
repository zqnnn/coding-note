//
// Created by zqn on 2019/6/21.
//
#include <algorithm>
using namespace std;
struct RotatedRect{

    int x,y,w,h;

    double theta;

};

//求旋转矩阵IOU

double CalIou(RotatedRect r1, RotatedRect r2){

}

//普通IOU
double calIou(RotatedRect r1, RotatedRect r2){
    int x2 = r1.x + r1.w;
    int y2 = r1.y + r1.h;

    int x4 = r2.x + r2.w;
    int y4 = r2.y + r2.h;

    int x = max(r1.x, r2.x);
    int y = max(r1.y, r2.y);

    int a = min(x2, x4);
    int b = min(y2, y4);

    int w = a - x;
    int h = b - y;
    int area = w * h;

    int area2 = r1.w * r1.h + r2.w * r2.h;

    double iou = area / (area2 - area);
    return iou;

}

