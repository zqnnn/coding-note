//
// Created by zqn on 2019/9/3.
//

#include <vector>
#include <iostream>
using namespace std;


//这道题给定我们一个数组，让我们返回一个新数组，对于每一个位置上的数是其他位置上数的乘积，并且限定了时间复杂度 O(n)，并且不让我们用除法。如果让用除法的话，那这道题就应该属于 Easy，因为可以先遍历一遍数组求出所有数字之积，然后除以对应位置的上的数字。但是这道题禁止我们使用除法，那么我们只能另辟蹊径。我们想，对于某一个数字，
// 如果我们知道其前面所有数字的乘积，同时也知道后面所有的数乘积，那么二者相乘就是我们要的结果
//我们先从前面遍历一遍，将乘积的累积存入结果 res 中，然后从后面开始遍历，用到一个临时变量 right，初始化为1，然后每次不断累积，最终得到正确结果，参见代码如下：
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        for(int i = 1; i < size; i++){
            result[i] = result[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i = size-1; i >= 0; i--){
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};


int main(){
    vector<int> nums = {1,2,3,4};
    Solution s;
    s.productExceptSelf(nums);
}