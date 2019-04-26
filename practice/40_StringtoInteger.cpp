//
// Created by zqn on 2019/4/26.
//
#include <string>
#include <cmath>
#include <limits.h>
#include <iostream>
using namespace std;


//字符串转为整数是很常用的一个函数，由于输入的是字符串，所以需要考虑的情况有很多种。关于验证一个字符串是否为数字，
// 请参见博客：http://www.cnblogs.com/grandyang/p/4084408.html，
// 该博客详细的讨论了各种情况，包括符号，自然数，小数点的出现位置，判断他们是否是数字。
// 那么这道题也应该有这么多种情况。但是这题只需要考虑数字和符号的情况：
//1. 若字符串开头是空格，则跳过所有空格，到第一个非空格字符，如果没有，则返回0.
//2. 若第一个非空格字符是符号+/-，则标记sign的真假，这道题还有个局限性，那就是在c++里面，+-1和-+1都是认可的，都是-1，而在此题里，则会返回0.
//3. 若下一个字符不是数字，则返回0. 完全不考虑小数点和自然数的情况，不过这样也好，起码省事了不少。
//4. 如果下一个字符是数字，则转为整形存下来，若接下来再有非数字出现，则返回目前的结果。
//5. 还需要考虑边界问题，如果超过了整形数的范围，则用边界值替代当前值。

class Solution {
public:
    int myAtoi(string str) {
        int leng = str.size();
        int flag = 1, res = 0;
        if(leng == 0) return 0;
        int i = 0;
        //跳过空格
        while(i < leng && str[i] == ' ') i++;
        //判断正负
        if (str[i] == '+' || str[i] == '-') {
            flag = (str[i++] == '+') ? 1 : -1;
        }
        while(i < leng && str[i] >= '0' && str[i] <= '9'){
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] - '0' > 7)){
                return (flag == 1) ? INT_MAX : INT_MIN;
            }
            res = 10 * res + (str[i++] - '0');
        }
        return res * flag;
    }
};

int main(){
    Solution s;
    int x =  s.myAtoi("    fad123");
    cout << x;
}