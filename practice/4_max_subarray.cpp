//
// Created by zqn on 2019/3/15.
//

#include <vector>
#include <iostream>
using namespace std;

//解法一：遍历，遇到负和抛弃之前的结果，重新积累，期间保留最大值
//class Solution {
//public:
//    int FindGreatestSumOfSubArray(vector<int> array) {
//        if(array.size() == 0){
//            return 0;
//        }
//        int count = 0;
//        int result = array[0];
//        for(int i=0; i<array.size(); i++){
//            //如果之前的加和是负数，舍弃之前的加和，等于当前的数
//            if(count <= 0){
//                count = array[i];
//            }
//            else
//                count += array[i];
//
//            //存储最大值
//            if(count > result)
//                result = count;
//        }
//        return result;
//    }
//};

//解法2：动态规划
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int sum = array[0], tempsum = array[0];
        for(int i = 1; i < array.size(); i++){
            tempsum = (tempsum < 0) ? array[i] : tempsum + array[i];
            sum = (tempsum > sum) ? tempsum : sum;
        }
        return sum;
    }
};


int main(){
    Solution s;
    vector<int> array = {1,-2,3,10,-4,7,2,-5};
    int count = s.FindGreatestSumOfSubArray(array);
    cout << count << endl;
}

