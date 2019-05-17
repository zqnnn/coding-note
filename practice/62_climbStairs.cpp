//
// Created by zqn on 2019/5/17.
//


//LeetCode（70）： 爬楼梯
//Easy！
//
//题目描述：
//
//假设你正在爬楼梯。需要 n 步你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//注意：给定 n 是一个正整数。
//
//示例 1：
//
//输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 步 + 1 步
//2.  2 步
//示例 2：
//
//输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 步 + 1 步 + 1 步
//2.  1 步 + 2 步
//3.  2 步 + 1 步
#include <iostream>
#include <vector>
using namespace std;


//递归 ！！！超时

//class Solution {
//public:
//    int climbStairs(int n) {
//        int res = 0;
//        selectStair(n, res);
//        return res;
//    }
//
//    void selectStair(int remainStep, int &count){
//        if(remainStep == 0){
//            count++;
//            return;
//        }
//        if(remainStep >= 2){
//            selectStair(remainStep-1, count);
//            selectStair(remainStep-2, count);
//        }
//        else if(remainStep == 1){
//            selectStair(remainStep-1, count);
//        }
//    }
//};

//这道题目实际上跟斐波那契数列非常相似，假设梯子有n层，那么如何爬到第n层呢，
// 因为每次只能爬1或2步，那么爬到第n层的方法要么是从第n-1层一步上来的，
// 要不就是从n-2层2步上来的，所以递推公式非常容易的就得出了：dp[n] = dp[n-1] + dp[n-2]。
// 因为递归计算了很多分支，效率很低，这里需要用动态规划 (Dynamic Programming) 来提高效率，代码如下：


class Solution{
public:
    int climbStairs(int n){
        if(n <= 1) return 1;
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp.back();
    }

};

//我们可以对空间进行进一步优化，
// 我们只用两个整型变量a和b来存储过程值，首先将a+b的值赋给b，
// 然后a赋值为原来的b，所以应该赋值为b-a即可。这样就模拟了上面累加的过程，而不用存储所有的值。

class Solution1 {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (n--) {
            b += a;
            a = b - a;
        }
        return a;
    }
};


int main(){
    Solution s;
    cout << s.climbStairs(5);
}