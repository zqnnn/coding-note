//
// Created by zqn on 2019/6/24.
//

#include <vector>
#include <iostream>
using namespace std;


//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res = res ^ nums[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,1,2,1,2};
    cout << s.singleNumber(nums);
}