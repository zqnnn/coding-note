//
// Created by zqn on 2019/6/3.
//

//给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
//
//返回 s 所有可能的分割方案。
//
//示例:
//
//输入: "aab"
//输出:
//[
//  ["aa","b"],
//  ["a","a","b"]
//]
//在真实的面试中遇到过这道题？

#include <vector>
#include <string>
using namespace std;


//这又是一道需要用DFS来解的题目，既然题目要求找到所有可能拆分成回文数的情况，
// 那么肯定是所有的情况都要遍历到，对于每一个子字符串都要分别判断一次是不是回文数，
// 那么肯定有一个判断回文数的子函数，还需要一个DFS函数用来递归，
// 再加上原本的这个函数，总共需要三个函数来求解。
//
// 我们将已经检测好的回文子串放到字符串数组out中，当s遍历完了之后，将out加入结果res中。
//
// 那么在递归函数中我们必须要知道当前遍历到的位置，用变量start来表示，
// 所以在递归函数中，如果start等于字符串s的长度，说明已经遍历完成，将out加入结果res中，并返回。

//否则就从start处开始遍历，由于不知道该如何切割，
// 所以我们要遍历所有的切割情况，即一个字符，两个字符，三个字符，等等。。

//首先判断取出的子串是否是回文串，调用一个判定回文串的子函数即可，
// 这个子函数传入了子串的起始和终止的范围，若子串是回文串，那么我们将其加入out，
// 并且调用递归函数，此时start传入 i+1，之后还要恢复out的状态。

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        dfs(s, 0, out, res);
        return res;
    }

    void dfs(string s, int start, vector<string> &out, vector<vector<string>> &res){
        if(start == s.size()) {
            res.push_back(out);
            return;
        }
        for(int i = start; i < s.size(); i++){
            if(!isPanlindrome(s, start, i)) continue;
            out.push_back(s.substr(start, i - start + 1));
            dfs(s, i+1, out, res);
            out.pop_back();
        }
    }

    bool isPanlindrome(string s, int start, int end){
        while (start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;

    }

};


//动态规划
//下面这种解法是基于解法一的优化，我们可以先建立好字符串s的子串回文的dp数组，
// 光这一部分就可以另出一个道题了 Palindromic Substrings，
// 当我们建立好这样一个二维数组dp，其中 dp[i][j] 表示 [i, j] 范围内的子串是否为回文串，
// 这样就不需要另外的子函数去判断子串是否为回文串了，大大的提高了计算的效率，岂不美哉？！
// 递归函数的写法跟解法一中的没啥区别，可以看之前的讲解，参见代码如下：



void dfs(string s, int start, vector<vector<bool>>& dp, vector<string> &out, vector<vector<string>> &res){
    if(start == s.size()) {
        res.push_back(out);
        return;
    }
    for(int i = start; i < s.size(); i++){
        if(!dp[start][i]) continue;
        out.push_back(s.substr(start, i - start + 1));
        dfs(s, i+1, dp, out, res);
        out.pop_back();
    }
}

vector<vector<string>> partition(string s){
    int n = s.size();
    vector<vector<string>> result;
    vector<string> out;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(s[i] == s[j] && (i - j <= 2 || dp[j+1][i-1]))
                dp[j][i] = true;
        }
    }
    dfs(s, 0, dp, out, result);
    return result;
}


int main(){
    vector<vector<string>> result;

    result = partition("aab");
    return 0;
}