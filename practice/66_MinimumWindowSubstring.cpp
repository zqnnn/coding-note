//
// Created by zqn on 2019/5/20.
//

#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

//LeetCode（76）： 最小覆盖子串
//Hard！
//
//题目描述：
//
//给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。
//
//示例：
//
//输入: S = "ADOBECODEBANC", T = "ABC"
//输出: "BANC"
//说明：
//
//如果 S 中不存这样的子串，则返回空字符串 ""。
//如果 S 中存在这样的子串，我们保证它是唯一的答案。
//解题思路：
//
//这道题的要求是要在O(n)的时间度里实现找到这个最小窗口字串，那么暴力搜索Brute Force肯定是不能用的，我们可以考虑哈希表，其中key是T中的字符，value是该字符出现的次数。
//
//- 我们最开始先扫描一遍T，把对应的字符及其出现的次数存到哈希表中。
//
//- 然后开始遍历S，遇到T中的字符，就把对应的哈希表中的value减一，直到包含了T中的所有的字符，纪录一个字串并更新最小字串值。
//
//- 将子窗口的左边界向右移，略掉不在T中的字符，如果某个在T中的字符出现的次数大于哈希表中的value，则也可以跳过该字符。
class Solution{
public:
    string minWindow(string s, string t){
        if(t.size() > s.size()) return "";
        string res = "";
        int left = 0, count = 0, minLen = s.size()+1;
        unordered_map<char, int> m;
        for(int i = 0; i < t.size(); i++){
            m[t[i]]++;
        }

        for(int right = 0; right < s.size(); right++){
            if(m[s[right]] > 0) {
                m[s[right]]--;
                if(m[s[right]] > 0) count++;
                while (count == t.size()){
                    if(right - left + 1 < minLen){
                        minLen = right - left + 1;
                        res = s.substr(left, minLen);
                    }
                    if(m[s[left]] > 0){
                        ++m[s[left]];
                        if(m[s[left]] > 0)
                            count--;
                    }
                    left++;
                }
            }

        }
        return res;
    }
};


class Solution1 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> counts;
        for (int i = 0; i < t.size(); i++) counts[t[i]]++;

        int cnt = 0;
        int min_len = INT32_MAX;
        int start = 0;
        int min_start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (counts[s[i]]-- > 0) cnt++;
            while (cnt == t.size()) {
                if (i - start + 1 < min_len) {
                    min_len = i - start + 1;
                    min_start = start;
                }
                if (counts[s[start++]]++ == 0) cnt--;
            }
        }
        return (min_len == INT32_MAX) ? "" : s.substr(min_start, min_len);
    }

};


int main(){
    Solution s;
    string  S = "ADOBECODEBANC", T = "ABC";
    cout << s.minWindow(S, T) << endl;
    Solution1 s1;
    cout  << s1.minWindow(S, T);
}