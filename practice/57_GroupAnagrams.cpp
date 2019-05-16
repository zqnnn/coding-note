//
// Created by zqn on 2019/5/16.
//


//LeetCode（49）： 字母异位词分组
//Medium！
//
//题目描述：
//
//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//
//示例:
//
//输入:
//["eat", "tea", "tan", "ate", "nat", "bat"]
//,
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//]
//说明：
//
//所有输入均为小写字母。
//不考虑答案输出的顺序。
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<int>> map;
        unordered_map<string, vector<int>>::iterator it;
        vector<string> temp;
        for(int i = 0; i < strs.size(); i++){
            string sub = strs[i];
            sort(sub.begin(), sub.end());
            map[sub].push_back(i);

        }
        it = map.begin();
        while (it != map.end()){
            vector<string> subres;
            for(int j = 0; j < it->second.size(); j++){
                cout << j << endl;
                cout << strs[it->second[j]] << endl;
                subres.push_back(strs[it->second[j]]);
            }
            res.push_back(subres);
            it++;
        }

        return res;


    }
};
//这道题让我们群组给定字符串集中所有的错位词（异位词），所谓的错位词就是两个字符串中字母出现的次数都一样，只是位置不同，
// 比如abc，bac, cba等它们就互为错位词，那么我们如何判断两者是否是错位词呢，
// 我们发现如果把错位词的字符顺序重新排列，那么会得到相同的结果，所以重新排序是判断是否互为错位词的方法，
// 由于错位词重新排序后都会得到相同的字符串，我们以此作为key，
// 将所有错位词都保存到字符串数组中，建立key和字符串数组之间的映射，最后再存入结果res中即可。
//看看人家写的好简单！！！
class Solution2 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};


int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> result = s.groupAnagrams(strs);
    return 0;
}