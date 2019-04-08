//
// Created by zqn on 2019/4/8.
//

//跳跃游戏
//给出一个非负整数数组，你最初定位在数组的第一个位置。　　　
//数组中的每个元素代表你在那个位置可以跳跃的最大长度。　　　　
//判断你是否能到达数组的最后一个位置。
//
//样例
//A = [2,3,1,1,4]，返回 true.
//
//A = [3,2,1,0,4]，返回 false.
//---------------------


//这个问题有两个方法，一个是贪心和 动态规划。
//
//贪心方法时间复杂度为O（N）。
//
//动态规划方法的时间复杂度为为O（n^2）。

//Solution：
//方法一.动态规划求解 使用动态规划求解问题，首先需要找到问题的状态和状态转化方程
//假设问题的状态，假设位置i(0≤i≤A.length)能够跳跃的最大长度为dp[i]。
//对于数组A = [2,3,1,1,4]， 则有：
//i = 0, dp[0] = A[0] + 0 = 2
//i = 1, if dp[i-1] = dp[0]≥i then dp[1] = max{A[1]+1,dp[0]}=4max{A[1]+1,dp[0]}=4 else dp[1] = 0
//i = 2, if dp[i-1] = dp[1] ≥ i then dp[2] = max{A[2]+2,dp[1]}max{A[2]+2,dp[1]} = 4 else dp[2] = 0
//基于上面的分析，其状态转换方程为：
//dp[i]={max{A[i]+i,dp[i−1]},if dp[i−1]≥i
// otherwise dp[i]=0

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;

        int dp[nums.size()];

        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(dp[i-1] >= i)
                dp[i] = max(nums[i] + i, dp[i-1]);
            else
                dp[i] = 0;
        }

        return dp[nums.size()-1] >= nums.size()-1;

    }
};


//方法二：贪心
//其实这题最好的解法不是DP，而是贪婪算法Greedy Algorithm，
// 因为我们并不是很关心每一个位置上的剩余步数，我们只希望知道能否到达末尾，
// 也就是说我们只对最远能到达的位置感兴趣，
// 所以我们维护一个变量reach，表示最远能到达的位置，初始化为0。
// 遍历数组中每一个数字，如果当前坐标大于reach或者reach已经抵达最后一个位置则跳出循环，
// 否则就更新reach的值为其和i + nums[i]中的较大值，其中i + nums[i]表示当前位置能到达的最大位置。

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int reach = 0;
    for(int i = 0; i < n; i++){
        if(i > reach || reach >= n-1)
            break;
        reach = max(reach, nums[i] + i);
    }

    return reach >= n-1;
}