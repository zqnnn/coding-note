//
// Created by zqn on 2019/5/23.
//
#include <vector>
#include <iostream>
using namespace std;
//LeetCode（88）：合并两个有序数组
//Easy！
//
//题目描述：
//
//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明:
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例:
//
//输入:
//nums1 = [1,2,3,0,0,0], m = 3
//nums2 = [2,5,6],       n = 3
//
//输出: [1,2,2,3,5,6]
//解题思路：

//最先想到的方法是建立一个新数组，然后逐个从A和B数组中取出元素比较，把较小的加入新数组，
// 然后在考虑A数组有剩余和B数组有剩余的两种情况，最后在把新数组的元素重新赋值到A数组中即可。
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> newNum;
    int i = 0, j = 0;
    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            newNum.push_back(nums1[i]);
            i++;
        }
        else{
            newNum.push_back(nums2[j]);
            j++;
        }
    }
    while(i >= m && j < n){
        newNum.push_back(nums2[j++]);
    }
    while(i < m && j >= n){
        newNum.push_back(nums1[i++]);
    }
    for(int i = 0; i < nums1.size(); i++){
        nums1[i] = newNum[i];
    }
}

//简单的方法
//不用申请新变量。算法思想是：由于合并后A数组的大小必定是m+n，
// 所以从最后面开始往前赋值，先比较A和B中最后一个元素的大小，
// 把较大的那个插入到m+n-1的位置上，再依次向前推。
// 如果A中所有的元素都比B小，那么前m个还是A原来的内容，没有改变。
// 如果A中的数组比B大的，
// 当A循环完了，B中还有元素没加入A，
// 直接用个循环把B中所有的元素覆盖到A剩下的位置。
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = m+n-1;
        m--;n--;
        while (m >= 0 && n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[count] = nums1[m];
                m--;
                count--;
            } else{
                nums1[count] = nums2[n];
                n--;
                count--;
            }

        }
        while (n >= 0)
            nums1[count--] = nums2[n--];
    }
};

int main(){
    vector<int> nums1 = {4,6,7,0,0,0}, nums2 = {2,5,6};
    Solution s;
    merge(nums1, 3, nums2, 3);
    for(int i = 0; i < nums1.size(); i++){
        cout << nums1[i] << " ";
    }
}