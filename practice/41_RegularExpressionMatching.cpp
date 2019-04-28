//
// Created by zqn on 2019/4/28.
//

//给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。
//
//'.' 匹配任意单个字符。
//'*' 匹配零个或多个前面的元素。
//匹配应该覆盖整个字符串 (s) ，而不是部分字符串。
//
//说明:
//
//s 可能为空，且只包含从 a-z 的小写字母。
//p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

#include <string>
#include <vector>
using namespace std;

//这道题分的情况的要复杂一些，需要用递归Recursion来解：
//
//- 若p为空，且s也为空，返回true，反之返回false
//
//- 若p的长度为1，且s长度也为1，且相同或是p为'.'则返回true，反之返回false
//
//- 若p的第二个字符不为*，且此时s为空则返回false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配
//
//- 若p的第二个字符为*，s不为空且字符匹配，调用递归函数匹配s和去掉前两个字符的p，若匹配返回true，否则s去掉首字母
//
//- 返回调用递归函数匹配s和去掉前两个字符的p的结果

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1) {
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        }
        if (p[1] != '*') {
            if (s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};
