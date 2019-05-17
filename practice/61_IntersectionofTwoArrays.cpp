//
// Created by zqn on 2019/5/17.
//

//题目分析：
//
//给定两个数组，求数组的交集。输出结果中的元素不唯一，输出数组可以无序。
//
//解题思路：
//
//1）对数组nums1进行排序；
//
//2）对数组nums2进行排序；
//
//3）遍历数组nums1和nums2中元素，并比较对应的元素，
//
//若相等，则将其保存到输出结果中，并变化两个数组对应的索引
//不等，则变化较小元素对应的索引即可。

#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> v;
//        sort(nums1.begin(),nums1.end());
//        sort(nums2.begin(),nums2.end());
//        set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(v));//求交集
//        return v;
//    }
//};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j ++;
            else{
                v.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return v;
    }
};
