//
// Created by zqn on 2019/8/19.
//

//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
//
//示例 1:
//
//输入: [1,2,3,1]
//输出: 4
//解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//     偷窃到的最高金额 = 1 + 3 = 4 。
//示例 2:
//
//输入: [2,7,9,3,1]
//输出: 12
//解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

//动态规划
//使用一个包含两个数字的数组cur_max，cur_max[0]表示上上次偷盗的最优解，cur_max[1]表示上次偷盗的最优解的递归公式如下

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1)
            return nums.empty() ? 0 : nums[0];
        int dp[size];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < size; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[size-1];
    }
};

int main(){
    Solution s;
    vector<int> nums = {2,7,9,3,1};

    cout << s.rob(nums);
}