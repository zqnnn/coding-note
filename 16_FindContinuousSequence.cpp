//
// Created by zqn on 2019/3/21.
//
#include <vector>
#include <iostream>
using namespace std;

//题目描述

//小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
// 但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
// 没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
// 现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

//输出描述
// 输出所有和为S的连续正数序列。
// 序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

//解题思路
// 延续我们上一道题的思路，可以先给定两个数（phigh = 2,plow = 1），
// 然后开始遍历求和，如果curSum大了，plow加1，如果curSum小了，phigh就加1；每次遇到curSum和sum相等了，
// 就将当前plow和phigh之间的数据全部压入临时tmp中，最后再将tmp压入最终结果result。

vector<vector<int> > FindContinuousSequence(int sum) {
    if (sum < 3)
        return {};
    int small = 1;
    int big = 2;
    vector<vector<int>> results;
    while (small < big) {
        //序列的中位数乘以序列的长度等于序列的和
        int s = (small + big) * (big - small + 1) / 2;
        if (s < sum) {
            big++;
        }
        else if(s > sum) {
            small++;
        }
        else{
            vector<int> result;
            for(int i = small; i <= big; i++)
                result.push_back(i);
            results.push_back(result);
            small++;
        }
    }
    return results;