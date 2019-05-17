//
// Created by zqn on 2019/5/17.
//
#include <limits.h>
#include <iostream>
using namespace std;

//LeetCode（50）：Pow(x, n)
//Medium！
//
//题目描述：
//
//实现 pow(x, n) ，即计算 x 的 n 次幂函数。
//
//示例 1:
//
//输入: 2.00000, 10
//输出: 1024.00000
//示例 2:
//
//输入: 2.10000, 3
//输出: 9.26100
//示例 3:
//
//输入: 2.00000, -2
//输出: 0.25000
//说明:
//
//-100.0 < x < 100.0
//n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

//超时，想得太简单了
//class Solution {
//public:
//    double myPow(double x, int n) {
//        if(n == 0)
//            return 1.00000;
//        else if(n > 0){
//            double res = x;
//            for(int i = 2; i < n+1; i++){
//                res = res * x;
//            }
//            return res;
//        }
//        else{
//            double res2 = 1/x;
//            for(int i = -2; i > n-1; i--){
//                res2 = res2 / x;
//            }
//            return res2;
//        }
//    }
//};


//我们可以用递归来折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，这时候我们再往回乘，
// 如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。
// 还有一点需要引起我们的注意的是n有可能为负数，对于n是负数的情况，我们可以先用其绝对值计算出一个结果再取其倒数即可

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return 1/power(x, -(n+1)) * 1/x;  //注意这个地方！！！INT_MIN取相反数会超过INT_MAX
        return power(x, n);
    }

    double power(double x, int n){
        if(n == 0) return 1;
        double half = power(x, n/2);
        if(n % 2 == 0) return half * half;
        return x * half * half;
    }
};
int main(){
    Solution s;
    double res = s.myPow(2.00000, -2);
    cout << res;
}