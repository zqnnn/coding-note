//
// Created by zqn on 2019/3/20.
//
#include <vector>
#include <iostream>
using namespace std;



//输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
//
//## 输出描述
//
//对应每个测试案例，输出两个数，小的先输出。
//
//## 解题思路
//
//暴力的时间复杂度为O(n^2)。
//
//下面我们想一下时间复杂度为O(n)的算法。我们可以定义两个指针，一个从前往后遍历（ahead），另一个从后往前遍历（behind）。
// 首先，我们比较第一个数字和最后一个数字的和curSum与给定数字sum，
// 如果curSum < sum，那么我们就要加大输入值，所以，ahead向后移动一位，重复之前的计算；
// 如果curSum > sum，那么我们就要减小输入值，所以，behind向前移动一位，重复之前的计算；
// 如果相等，那么这两个数字就是我们要找的数字，直接输出即可。

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int* low = &array[0];
        int* high = &array[array.size() - 1];
        int s = *low + *high;
        //vector<int> result = {};
        while(s != sum){
            if(s > sum){
                high = high - 1;
                s = *low + *high;
            }
            if(s < sum){
                low = low + 1;
                s = *low + *high;
            }
        }

        int a = *low;
        int b = *high;
        vector<int> result = {a, b};
        return result;
}


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        int length = array.size();
        if(length < 1)
            return {};
        int low = 0;
        int high = length - 1;
        while(high > low){
            int s = array[low] + array[high];
            if(s == sum){
                result.push_back(array[low]);
                result.push_back(array[high]);
                break;
            }
            else if(s > sum){
                high--;
            }
            else
                low ++;
        }
        return result;
    }
};

int main(){
    vector<int> data = {1,2,3,4,5};
    int k =  7;
    vector<int> a = FindNumbersWithSum(data, k);
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
}