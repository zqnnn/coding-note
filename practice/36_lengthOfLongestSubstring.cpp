//
// Created by zqn on 2019/4/21.
//

//描述
//给定一个字符串，找出不含有重复字符的最长子串的长度。
//
//示例：
//给定 “abcabcbb” ，没有重复字符的最长子串是 “abc” ，那么长度就是3。
//
//给定 “bbbbb” ，最长的子串就是 “b” ，长度是1。
//
//给定 “pwwkew” ，最长子串是 “wke” ，长度是3。请注意答案必须是一个子串，”pwke” 是 子序列 而不是子串。
//---------------------

#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;


//建立一个256位大小的整型数组来代替哈希表，这样做的原因是ASCII表共能表示256个字符，所以可以记录所有字符，
// 然后我们需要定义两个变量res和left，其中res用来记录最长无重复子串的长度，left指向该无重复子串左边的起始位置，
// 然后我们遍历整个字符串，对于每一个遍历到的字符，如果哈希表中该字符串对应的值为0，说明没有遇到过该字符，
// 则此时计算最长无重复子串，i - left +１，其中ｉ是最长无重复子串最右边的位置，left是最左边的位置，
// 还有一种情况也需要计算最长无重复子串，就是当哈希表中的值小于left，这是由于此时出现过重复的字符，left的位置更新了，
// 如果又遇到了新的字符，就要重新计算最长无重复子串。最后每次都要在哈希表中将当前字符对应的值赋值为i+1。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[256] = {0};
        int left = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if(a[s[i]] == 0 || a[s[i]] < left){
                res = max(i - left + 1, res);

            }
            else{
                left = a[s[i]];
            }
            a[s[i]] = i + 1; //更新当前字符最后一次出现的位置
        }
        return res;
    }
};



// 使用SET
int leng(string s){
    set<char> t;
    int res = 0, left = 0, right = 0;
    while (right < s.size()){
        if(t.find(s[right]) == t.end()){
            t.insert(s[right++]);
            res = max(res, int(t.size()));
        } else{
            t.erase(s[left++]);
        }
    }

    return res;
}

//使用HashMap
int length(string s){
    int res = 0, left = 0;
    unordered_map<char, int> m;
    for(int i = 0; i < s.size(); i++){
        left = max(left, m[s[i]]);
        m[s[i]] = i + 1;
        res = max(res, i - left + 1);
    }

    return res;
}

int main(){
    string s = "ptydfgh";
    Solution so;
    cout << length(s);
}