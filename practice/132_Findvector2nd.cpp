//
// Created by zqn on 2019/9/8.
//


//在一个二维数组中（每个一维数组的长度相同），
// 每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。


//从左下角开始找！！！

#include <vector>
using namespace std;


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size(), n = array[0].size();
        for(int i = m - 1, j = 0; i >= 0 && j < n; ){
            if(array[i][j] ==  target) return true;
            else if(array[i][j] < target) {
                j++;
            }
            else {
                i--;
            }
        }
        return false;
    }
};


int main(){
    vector<vector<int> > array = {{1,4,5,6},{2,6,7,8},{3,8,9,12}};
    Solution s;
    s.Find(8, array);
}