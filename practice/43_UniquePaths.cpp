//
// Created by zqn on 2019/4/29.
//

//LeetCode（62）：不同路径
//Medium！
//
//题目描述：
//
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//问总共有多少条不同的路径？
//
//
//
//例如，上图是一个7 x 3 的网格。有多少可能的路径？
//
//说明：m 和 n 的值均不超过 100。
//
//示例 1:
//
//输入: m = 3, n = 2
//输出: 3
//解释:
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右 -> 向右 -> 向下
//2. 向右 -> 向下 -> 向右
//3. 向下 -> 向右 -> 向右
//示例 2:
//
//输入: m = 7, n = 3
//输出: 28


//这是一个动态规划问题，动态规划的思路就是通过一系列的子问题来实现最终问题的求解。
// 那么具体到这道题，可以这么理解，在这个矩形网格框内，第一行和第一列中的每一位置，到达的可能路径都为1。
// 对其他位置，到达的可能路径数量为其正上面位置对应路径的数量加上左边路径的数量（因为只可以向下走或者向右走）。
// 如下表可以看出这一点。
//0	1	1	1	1	1	1
//1	2	3	4	5	6	7
//1	3	6	10	15	21	28

#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> info(n,vector<int>(m,0));
        for(int i=0;i<m;++i)
        {
            info[0][i]=1;
        }
        for(int i=0;i<n;++i)
        {
            info[i][0]=1;
        }
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                info[j][i]=info[j-1][i]+info[j][i-1];
            }
        }
        return info[n-1][m-1];
    }
};

//这里为了节省空间，我们使用一维数组dp，一行一行的刷新也可以。

// DP
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

//其实还有另一种很数学的解法，参见https://blog.csdn.net/linhuanmars/article/details/22126357
//

//其实就是机器人总共走m+n-2步，其中m-1步往下走，n-1步往右走，本质上就是一个组合问题，也就是从m+n-2个不同元素中每次取出m-1个元素的组合数。

int uniquePaths(int m, int n) {
    double dom = 1;
    double dedom = 1;
    int small = m<n? m-1:n-1;
    int big = m<n? n-1:m-1;
    for(int i=1;i<=small;i++)
    {
        dedom *= i;
        dom *= small+big+1-i;
    }
    return (int)(dom/dedom);
}
