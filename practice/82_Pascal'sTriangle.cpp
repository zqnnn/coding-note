//
// Created by zqn on 2019/5/29.
//

//LeetCode（118）：杨辉三角
//Easy！
//
//题目描述：
//
//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

//在杨辉三角中，每个数是它左上方和右上方的数的和。
//
//示例:
//
//输入: 5
//输出:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//]
#include <vector>
#include <iostream>
using namespace std;


////解题思路：
////
////杨辉三角是二项式系数的一种写法，如果熟悉杨辉三角的五个性质，那么很好生成，可参见http://www.cnblogs.com/grandyang/p/4031536.html，
/// 具体生成算法：每一行的首个和结尾一个数字都是1，从第三行开始，中间的每个数字都是上一行的左右两个数字之和。
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)  return {};
        vector<vector<int>> res;
        res.push_back({1});
        for(int i = 1; i < numRows; i++){
            vector<int> tmp3(i+1, 0);
            for(int j = 0; j < i+1; j++){
                if(j == 0 || j == i){
                    tmp3[j] = 1;
                } else{
                    tmp3[j] = res[i-1][j-1] + res[i-1][j];
                }
            }
            res.push_back(tmp3);
        }
        return res;
    }
};


int main(){
    int num = 3;
    //cin >> num;
    Solution s;
    vector<vector<int>> res =  s.generate(num);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<< ' ';
        }
    }
    return 0;
}