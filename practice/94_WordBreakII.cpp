//
// Created by zhangqianni on 2019-07-24.
//

//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
//
//说明：
//
//分隔时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//
//输入:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//输出:
//[
//  "cats and dog",
//  "cat sand dog"
//]
//示例 2：
//
//输入:
//s = "pineapplepenapple"
//wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//输出:
//[
//  "pine apple pen apple",
//  "pineapple pen apple",
//  "pine applepen apple"
//]
//解释: 注意你可以重复使用字典中的单词。
//示例 3：
//
//输入:
//s = "catsandog"
//wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出:
//[]
//

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//这道题是之前那道Word Break 拆分词句的拓展，那道题只让我们判断给定的字符串能否被拆分成字典中的词，
// 而这道题加大了难度，让我们求出所有可以拆分成的情况，就像题目中给的例子所示。

//像这种返回结果要列举所有情况的题，十有八九都是要用递归来做的。
//要避免重复计算，如何避免呢，还是看上面的分析，如果当s变成 "sanddog"的时候，那么此时我们知道其可以拆分成sand和dog，
// 当某个时候如果我们又遇到了这个 "sanddog"的时候，我们难道还需要再调用递归算一遍吗，
// 当然不希望啦，所以我们要将这个中间结果保存起来，由于我们必须要同时保存s和其所有的拆分的字符串，
// 那么可以使用一个HashMap，来建立二者之间的映射


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> map;
        return helper(s, wordDict, map);
    }

    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& map){
        if(map.count(s)) return map[s];
        if(s.empty()) return {""};
        vector<string> res;
        for(string word : wordDict){
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = helper(s.substr(word.size()), wordDict, map);
            for (string str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return map[s] = res;
    }
};




int main(){
    vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    Solution s;
    vector<string> res = s.wordBreak("pineapplepenapple", wordDict);
}