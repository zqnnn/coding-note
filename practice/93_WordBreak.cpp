//
// Created by zhangqianni on 2019-07-23.
//


//Description

//原题
//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//
//说明：
//
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入: s = “leetcode”, wordDict = [“leet”, “code”]
//输出: true
//解释: 返回 true 因为 “leetcode” 可以被拆分成 “leet code”。
//
//示例 2：
//
//输入: s = “applepenapple”, wordDict = [“apple”, “pen”]
//输出: true
//解释: 返回 true 因为 “applepenapple” 可以被拆分成 “apple pen apple”。
//注意你可以重复使用字典中的单词。
//
//示例 3：
//
//输入: s = “catsandog”, wordDict = [“cats”, “dog”, “sand”, “and”, “cat”]
//输出: false


#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


//方法一：
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //记忆化递归！
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return my_word(s, wordSet);

    }

    bool my_word(string s, unordered_set<string> &wordSet){
        if(word_map.count(s)) return word_map[s];
        if(wordSet.count(s)) return word_map[s] = true;
        for(int i = 1; i < s.size(); i++){
            string temp1 = s.substr(0, i);
            string temp2 = s.substr(i); //截取i到结尾
            if(my_word(temp1, wordSet) && wordSet.count(temp2))
                return word_map[s] = true;
        }
        return word_map[s] = false;
    }

private:
    unordered_map<string, bool> word_map; //记忆出现过的子串


};


//方法二：玩子数组或者子字符串且求极值的题，基本就是 DP 没差了
//DP 解法的两大难点，定义 dp 数组跟找出状态转移方程
//先来看 dp 数组的定义，这里我们就用一个一维的 dp 数组，其中 dp[i] 表示范围 [0, i) 内的子串是否可以拆分
//注意这里 dp 数组的长度比s串的长度大1，是因为我们要 handle 空串的情况，我们初始化 dp[0] 为 true,然后开始遍历。
//注意这里我们需要两个 for 循环来遍历，因为此时已经没有递归函数了，所以我们必须要遍历所有的子串
//我们用j把 [0, i) 范围内的子串分为了两部分，[0, j) 和 [j, i)，其中范围 [0, j) 就是 dp[j]，范围 [j, i) 就是 s.substr(j, i-j)
//其中 dp[j] 是之前的状态，我们已经算出来了，可以直接取，只需要在字典中查找 s.substr(j, i-j) 是否存在了，
// 如果二者均为 true，将 dp[i] 赋为 true，并且 break 掉，此时就不需要再用j去分 [0, i) 范围了，因为 [0, i) 范围已经可以拆分了。
// 最终我们返回 dp 数组的最后一个值，就是整个数组是否可以拆分的布尔值了，代码如下：


bool wordBreak(string s, vector<string>& wordDict){
    unordered_set<string> word_set(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size()+1, false); //dp数组

    dp[0] = true; //空字符串
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < i; j++){
            if(dp[j] && word_set.count(s.substr(j, i - j))){
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}



int main(){
    Solution s;
    vector<string> v = {"cats", "dog", "sand", "and", "cat"};
    s.wordBreak("catsandog", v);
}