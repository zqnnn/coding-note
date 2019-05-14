//
// Created by zqn on 2019/5/14.
//


//LeetCode（29）： 两数相除
//Medium！
//
//题目描述：
//
//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
//
//返回被除数 dividend 除以除数 divisor 得到的商。
//
//示例 1:
//
//输入: dividend = 10, divisor = 3
//输出: 3
//示例 2:
//
//输入: dividend = 7, divisor = -3
//输出: -2
//说明:
//
//被除数和除数均为 32 位有符号整数。
//除数不为 0。
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。

#include <iostream>
#include <limits.h>
using namespace std;
//当被除数大于等于除数时(否则的话就为0了)，我们设置两个变量t和i，
// 并分别初始化为除数和1(最小的情况)，当被除数大于等于t的二倍时，
// 将t和i同时扩大二倍(左移)，并将返回值加上i，除数减去t。
// 拿十进制举例:29除以8，8扩大二倍，16小于29，再扩大二倍，超过29，
// 于是29减去之前的16，返回值加上2。第二次循环时因为此时的13小于8的二倍，
// 故加上1，整个循环结束，最终结果为2+1=3，符合要求。
// 此外还要注意判断结果正负号时亦或的作用。 代码如下:

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int flag = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long m  = abs((long long)dividend);
        long long n = abs((long long)divisor);
        long long result = 0;
        if (n == 1) return flag == 1 ? m : -m;
        while (n <= m){
            long long t = n, i = 1;
            while(m >= (t << 2)){
                i <<= 1;
                t <<= 1;
            }
            result = result + i;
            m = m - t;
        }
        return flag > 0? result : -result;
    }
};

int main(){
    Solution s;
    int result = s.divide(2147482647, 2);
    cout << result;

}