//
// Created by zqn on 2019/4/22.
//
#include <string>
#include <vector>
using namespace std;


// 对于字符串str，假设dp[i,j]=1表示str[i...j]是回文子串，那个必定存在dp[i+1,j-1]=1。这样最长回文子串就能分解成一系列子问题，可以利用动态规划求解了。
// 首先构造状态转移方程
// 上面的状态转移方程表示，当str[i]=str[j]时，如果str[i+1...j-1]是回文串，则str[i...j]也是回文串；如果str[i+1...j-1]不是回文串，则str[i...j]不是回文串。
// 初始状态
//dp[i][i]=1
//dp[i][i+1]=1 if str[i]==str[i+1]
// 上式的意义是单个字符，两个相同字符都是回文串。
//这里我们需要用一个二维数组dp来作为备忘录，记录子问题的结果，以便重复的计算。这也是动态规划的精髓所在。不过这种做法的算法复杂度也是O(n^2)
class Solution1 {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return " ";
        int length = s.size();
        if(length == 1)
            return s;
        int dp[length][length];
        int longst = 1;
        int start = 0;

        //最长长度为2的情况
        for(int i = 0; i < length; i++){
            dp[i][i] = 1;
            while (i < length - 1){
                if(s[i] == s[i+1]){
                    dp[i][i+1] = 1;
                    start = i;
                    longst = 2;
                }
            }
        }

        for(int l = 3; l < length; l++){
            for(int i = 0; i+l-1 < length; i++){
                int j = i+l-1;
                if(s[i] == s[j] && dp[i+1][j-1]==1){
                    dp[i][j] = 1;
                    start = i;
                    longst = j;
                }
            }

        }

        return s.substr(start, longst);

    }
};



//Manacher算法
//Manacher算法首先通过在每个字符的两边都插入一个特殊的符号（未在字符串中出现过），
// 将所有可能的回文子串都转换成奇数。例如"aba"的两边都插入字符'#'就变成了"#a#b#a#"。
// 为了更好处理越界问题，可以在字符串的开始和结尾加入另一个特殊字符，
// 例如在"#a#b#a#"的开始和结尾插入字符'%'变成"%#a#b#a#%"。


// P数组简介
// Manacher算法利用一个辅助数组P[i]表示以字符S[i]为中心的最长回文子串的最右（左）字符到S[i]的距离（包括S[i]）。
// 例如以S[i]为中心的最长回文子串是S[l..r]，则P[i]=r-i+1。


class Solution {
public:
    string longestPalindrome(string s){
        string manaStr = "$#"; //首先构造出新的字符串
        for (int i=0;i<s.size();i++) {
            manaStr += s[i];
            manaStr += '#';
        }
        vector<int> rd(manaStr.size(), 0);//用一个辅助数组来记录最大的回文串长度，注意这里记录的是新串的长度，原串的长度要减去1
        int pos = 0, mx = 0;
        int start = 0, maxLen = 0;
        for (int i = 1; i < manaStr.size(); i++)
        {
            rd[i] = i < mx ? min(rd[2 * pos - i], mx - i) : 1;
            while (i+rd[i]<manaStr.size() && i-rd[i]>0 && manaStr[i + rd[i]] == manaStr[i - rd[i]])//这里要注意数组越界的判断，源代码没有注意，release下没有报错
                rd[i]++;
            if (i + rd[i] > mx) //如果新计算的最右侧端点大于mx,则更新pos和mx
            {
                pos = i;
                mx = i + rd[i];
            }
            if (rd[i] - 1 > maxLen)
            {
                start = (i - rd[i]) / 2;
                maxLen = rd[i] - 1;
            }
        }
        return s.substr(start, maxLen);
    }
};