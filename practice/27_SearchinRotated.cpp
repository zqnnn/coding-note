//
// Created by zqn on 2019/4/1.
//
#include <vector>
#include <iostream>
using namespace std;

//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//
//( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//
//搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
//
//你可以假设数组中不存在重复的元素。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//示例 1:
//
//输入: nums = [4,5,6,7,0,1,2], target = 0
//输出: 4
//示例 2:
//
//输入: nums = [4,5,6,7,0,1,2], target = 3
//输出: -1
int search(vector<int>& nums, int target) {
    int first = 0;
    int last = nums.size();
    while(first != last){
        const int mid = (first + last) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[first] <= nums[mid]){
            if(nums[first] <= target && target < nums[mid]){
                last = mid;
            }
            else
                first = mid + 1;
        }
        else{
            if(nums[mid] < target && target <= nums[last-1]){
                first = mid + 1;
            }
            else
                last = mid;
        }
    }
    return -1;
}


int searchrotate(vector<int> &nums, int target){
    int first = 0, last = nums.size();
    while (first < last){
        int mid = (first + last) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[first] < nums[mid]){
            if(nums[mid] > target && nums[first] <= target){
                last = mid;
            }
            else{
                first = mid + 1;
            }
        }
        else{
            if(nums[mid] < target && nums[last-1] >= target){
                first = mid + 1;
            }
            else{
                last = mid;
            }
        }
    }
    return -1;
}


int main(){
    vector<int> num = {4,5,6,7,0,1,2};
    cout << search(num, 1)<<endl;
    cout << searchrotate(num, 1)<<endl;
}