//
// Created by zqn on 2019/5/29.
//
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

//LeetCode（121）：买卖股票的最佳时机
//Easy！
//
//题目描述：
//
//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//
//如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//
//注意你不能在买入股票前卖出股票。
//
//示例 1:
//
//输入: [7,1,5,3,6,4]
//输出: 5
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
//示例 2:
//
//输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
//解题思路：
//
//只需要遍历一遍数组，用一个变量记录遍历过数中的最小值，
// 然后每次计算当前值和这个最小值之间的差值最为利润，
// 然后每次选较大的利润来更新。当遍历完成后当前利润即为所求
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX, high = 0;
        for(int i = 0; i < prices.size(); i++){
            low = min(low, prices[i]);
            high = max(high, prices[i]-low);
        }
        return high;
    }
};

int main()
{
    vector<int> vec = {7,6,4,3,1};
//    int temp=0;
//    while(cin >> temp) //如果不确定输入数字个数，可以用这种方式
//    {
//        vec.push_back(temp); //填充数据
//    }
    Solution s;
    cout << s.maxProfit(vec);
    return 0;
}
