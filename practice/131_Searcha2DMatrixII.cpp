//
// Created by zqn on 2019/9/4.
//
#include <vector>
using namespace std;

//搜索一个二维矩阵之二

//如果我们观察题目中给的那个例子，我们可以发现有两个位置的数字很有特点，左下角和右上角的数。
// 左下角的18，往上所有的数变小，往右所有数增加，那么我们就可以和目标数相比较，
// 如果目标数大，就往右搜，如果目标数小，就往上搜。这样就可以判断目标数是否存在。
// 当然我们也可以把起始数放在右上角，往左和下搜，停止条件设置正确就行。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        if(target < matrix[0][0] || target > matrix.back().back())
            return false;
        int m = matrix.size()-1, n = 0;
        while (true){
            if(matrix[m][n] > target) m--;
            else if(matrix[m][n] < target) n++;
            else return true;
            if(m < 0 || n >= matrix[0].size()) break;
        }
        return false;
    }


};


int main(){
    vector<vector<int>> matrix = {{1,   4,  7, 11, 15},
                                  {2,   5,  8, 12, 19},
                                          {3,   6,  9, 16, 22},
                                          {10, 13, 14, 17, 24},
                                          {18, 21, 23, 26, 30}};

    Solution s;
    s.searchMatrix(matrix, 7);
}