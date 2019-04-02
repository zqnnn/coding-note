//
// Created by zqn on 2019/4/2.
//



#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//接雨水
//Hard！
//
//题目描述：
//
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
//
//
//上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
//
//示例:
//
//输入: [0,1,0,2,1,0,1,3,2,1,2,1]
//输出: 6
//解题思路：
//这个算法需要left和right两个指针分别指向数组的首尾位置，从两边向中间扫描，
// 在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是left指向的值，
// 则从左向右扫描，如果较小值是right指向的值，则从右向左扫描，若遇到的值比当前较小值小，
// 则将差值存入结果，如遇到的值大，则重新确定新的窗口范围，以此类推直至left和right指针重合。
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r){
            int mn = min(height[l], height[r]);
            if(mn == height[l]){
                ++l;
                while (l < r && height[l] < mn){
                    res+= mn - height[l++];
                }
            }
            else{
                --r;
                while (l < r && height[r] < mn){
                    res += mn - height[r--];
                }
            }
        }
        return res;
    }
};