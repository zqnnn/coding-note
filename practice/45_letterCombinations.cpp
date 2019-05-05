//
// Created by zqn on 2019/5/3.
//
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

//LeetCode（17）：电话号码的字母组合
//Medium！
//
//题目描述：
//
//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

//示例:
//
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//说明:
//尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
//
//解题思路：
//
//这道题让我们求电话号码的字母组合，即数字2到9中每个数字可以代表若干个字母，然后给一串数字，求出所有可能的组合。

//递归法 最短路径=》BFS    所有路径=》DFS
//我们用递归Recursion来解，要建立一个字典，用来保存每个数字所代表的字符串，然后还需要一个变量level，记录当前生成的字符串的字符个数。

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        DFS(digits, dict, 0, "", res);
        return res;
    }

    void DFS(string digits, string dict[], int level, string out, vector<string> &res){
        if(level == digits.size()) res.push_back(out);
        else{
            string str = dict[digits[level] - '2'];
            for(int i = 0; i < str.size(); i++){
                out.push_back(str[i]);
                DFS(digits, dict, level+1, out, res);
                out.pop_back();
            }
        }
    }
};

int main(){
    string di = "23";
    Solution s;
    vector<string> so = s.letterCombinations(di);
    for(int i = 0; i < so.size(); i++){
        cout << so[i] << endl;
    }
    return 0;
}