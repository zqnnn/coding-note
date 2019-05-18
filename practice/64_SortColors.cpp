//
// Created by zqn on 2019/5/18.
//

//LeetCode（75）：分类颜色
//Medium！
//
//题目描述：
//
//给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
//此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//
//注意:
//不能使用代码库中的排序函数来解决这道题。
//
//示例:
//
//输入: [2,0,2,1,1,0]
//输出: [0,0,1,1,2,2]
//进阶：
//
//一个直观的解决方案是使用计数排序的两趟扫描算法。
//首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
//你能想出一个仅使用常数空间的一趟扫描算法吗？

#include <vector>
#include <iostream>
using namespace std;


//解题思路：
//
//这道题的本质还是一道排序的题，题目中给出提示说可以用计数排序，需要遍历数组两遍，那么先来看这种方法，因为数组中只有三个不同的元素，所以实现起来很容易。
//
//- 首先遍历一遍原数组，分别记录0,1,2的个数
//- 然后更新原数组，按个数分别赋上0，1，2
//class Solution {
//public:
//    void sortColors(vector<int>& nums) {
//        int a[3];
//        int index = 0;
//        for(int i = 0; i < nums.size(); i++){
//            a[nums[i]]++;
//        }
//        for(int i = 0; i < 3; i++){
//            for(int j = 0; j < a[i]; j++){
//                nums[index++] = i;
//            }
//        }
//    }
//
//};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int blue=nums.size()-1, red=0;
        for (int i=0; i<=blue; i++) {
            while (nums[i]==2 && i<blue) swap(nums[i], nums[blue--]);
            while (nums[i]==0 && i>red) swap(nums[i], nums[red++]);
        }
    }
};


int main(){
    vector<int> nums = {1,2,0};

    Solution s;
    s.sortColors(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " " << endl;
    }
    return 0;
}