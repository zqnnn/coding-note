//
// Created by zqn on 2019/5/22.
//
#include <vector>
#include <iostream>
using namespace std;

//LeetCode（81）： 搜索旋转排序数组 II
//Medium！
//
//题目描述：
//
//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
//( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
//
//编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

//这道是之前那道 Search in Rotated Sorted Array 在旋转有序数组中搜索 的延伸，
// 现在数组中允许出现重复数字，这个也会影响我们选择哪半边继续搜索，
// 由于之前那道题不存在相同值，我们在比较中间值和最右值时就完全符合之前所说的规律：
// 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的。
// 而如果可以有重复值，就会出现来面两种情况，[3 1 1] 和 [1 1 3 1]，对于这两种情况中间值等于最右值时，
// 目标值3既可以在左边又可以在右边，那怎么办么，对于这种情况其实处理非常简单，只要把最右值向左一位即可继续循环
// ，如果还相同则继续移，直到移到不同值为止，
// 然后其他部分还采用 Search in Rotated Sorted Array 在旋转有序数组中搜索 中的方法，可以得到代码如下。

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right){
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;

            if(nums[left] < nums[mid]){
                if(nums[mid] > target && nums[left] <= target){
                    right = mid;
                } else{
                    left = mid + 1;
                }
            }
            else if(nums[left] == nums[mid]){
                left++;
            }
            else{
                if(nums[mid] < target && nums[right-1] >= target){
                    left = mid + 1;
                } else{
                    right = mid;
                }
            }
        }

        return false;

    }
};


int main(){
    vector<int> num = {2,5,6,0,0,1,2};
    Solution s;
    cout << s.search(num, 3)<<endl;

}