//
// Created by zqn on 2019/8/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};


//上面方法虽然简洁，但是确不是本题真正想考察的东西，可以说有一定的偷懒嫌疑。
// 这道题最好的解法应该是下面这种做法，用到了快速排序 Quick Sort 的思想，这里排序的方向是从大往小排。对快排不熟悉的童鞋们随意上网搜些帖子看下吧，多如牛毛啊，总有一款适合你。
// 核心思想是每次都要先找一个中枢点 Pivot，然后遍历其他所有的数字，像这道题从大往小排的话，就把大于中枢点的数字放到左半边，把小于中枢点的放在右半边，
// 这样中枢点是整个数组中第几大的数字就确定了，虽然左右两部分各自不一定是完全有序的，但是并不影响本题要求的结果，因为左半部分的所有值都大于右半部分的任意值，所以我们求出中枢点的位置，
// 如果正好是 k-1，那么直接返回该位置上的数字；如果大于 k-1，说明要求的数字在左半部分，更新右边界，再求新的中枢点位置；反之则更新右半部分，求中枢点的位置；不得不说，这个思路真的是巧妙啊～



int partiton(vector<int>& nums, int left, int right){
    int pivot = nums[left], l = left+1, r = right;
    while (l <= r){
        if(nums[l] < pivot && nums[r] > pivot){
            swap(nums[l++], nums[r--]);
        }
        if(nums[l] >= pivot) l++;
        if(nums[r] <= pivot) r--;
    }
    swap(nums[left], nums[r]);
    return r;

}

int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size()-1;
    while (true){
        int pos = partiton(nums, left, right);
        if(pos == k-1) return nums[pos];
        else if(pos < k-1) left = pos + 1;
        else right = pos - 1;
    }
}