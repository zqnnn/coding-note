//
// Created by zqn on 2019/5/15.
//
//LeetCode（44）： 通配符匹配
//Hard！
//
//题目描述：
//
//给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
//
//'?' 可以匹配任何单个字符。
//'*' 可以匹配任意字符串（包括空字符串）。
//两个字符串完全匹配才算匹配成功。
//
//说明:
//
//s 可能为空，且只包含从 a-z 的小写字母。
//p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
//示例 1:
//
//输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。
//示例 2:
//
//输入:
//s = "aa"
//p = "*"
//输出: true
//解释: '*' 可以匹配任意字符串。
//示例 3:
//
//输入:
//s = "cb"
//p = "?a"
//输出: false
//解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
//示例 4:
//
//输入:
//s = "adceb"
//p = "*a*b"
//输出: true
//解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
//示例 5:
//
//输入:
//s = "acdcb"
//p = "a*c?b"
//输入: false
//解题思路：
//
//这道题也能用动态规划Dynamic Programming来解，
// 写法跟之前那道题Regular Expression Matching很像，但是还是不一样。
// 外卡匹配和正则匹配最大的区别就是在星号的使用规则上，
// 对于正则匹配来说，星号不能单独存在，前面必须要有一个字符，
// 而星号存在的意义就是表明前面这个字符的个数可以是任意个，包括0个，
// 那么就是说即使前面这个字符并没有在s中出现过也无所谓，只要后面的能匹配上就可以了。
//
// 而外卡匹配就不是这样的，外卡匹配中的星号跟前面的字符没有半毛钱关系，
// 如果前面的字符没有匹配上，那么直接返回false了，根本不用管星号。
// 而星号存在的作用是可以表示任意的字符串，当然只是当匹配字符串缺少一些字符的时候起作用，
// 当匹配字符串包含目标字符串没有的字符时，将无法成功匹配。

//这个问题的难点在于判断*匹配多少次的问题。所以我们不妨从最简单的情况开始考虑，
// 我们首先判断p的第一个元素是不是*。
// 如果p的第一个元素是*的话，那我们只要考虑*是匹配零次还是匹配一次即可，
// 也就是我们只要判断isMatch(s[1:],p)和isMatch(s,p[1:])。
//
//如果p的第一个元素不是*的话，我们只要判断s[0]与p[0]能否匹配。
// 所以我们可以非常迅速的写出动态规划转移方程。
//---------------------
//f(i,j)=f(i,j−1) or f(i−1,j)  if  p[j−1]=′∗′
//f(i,j)=f(i−1,j−1) and  (s[i−1]==p[j−1]∣∣p[j−1]==′?′)  if  p[j−1]≠′∗′

//f(i,j)表示输入s[0:i]和输入p[0:j]时的匹配结果。
//---------------------


#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //先将所有值设为false
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        //当s为空
        for(int i = 1; i <=n; i++){
            if(p[i-1] == '*')
                dp[0][i] = dp[0][i-1];
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
            }
        }
        return dp[m][n];

    }
};