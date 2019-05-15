//
// Created by zqn on 2019/5/15.
//

//LeetCode（38）： 报数
//Easy！
//
//题目描述：
//
//报数序列是指一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 被读作  "one 1"  ("一个一") , 即 11。
//11 被读作 "two 1s" ("两个一"）, 即 21。
//21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
//
//给定一个正整数 n ，输出报数序列的第 n 项。
//
//注意：整数顺序将表示为一个字符串。
//
//示例 1:
//
//输入: 1
//输出: "1"
//示例 2:
//
//输入: 4
//输出: "1211"
//解题思路：
//
//题目描述的不是很清楚，其实就是第i+1个字符串是第i个字符串的读法，第一字符串为 “1”
//
//比如第四个字符串是1211，它的读法是 1个1、1个2,2个1，因此第五个字符串是111221。
//
//第五个字符串的读法是：3个1、2个2、1个1，因此第六个字符串是312211
//
//......
//
//简单的模拟就可以。
//
//这道计数和读法问题还是第一次遇到，看似挺复杂，其实仔细一看，算法很简单，
// 就是对于前一个数，找出相同元素的个数，把个数和该元素存到新的string里。
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        if(n == 1) return "1";
        if(n == 2) return "11";
        string result = "11";
        for(int i = 3; i < n+1; i++){
            string pre = result;
            string cur = "";
            int count = 1;
            for(int j = 0; j < pre.size(); j++){
                while (j+1 < pre.size() && pre[j] == pre[j+1]){
                    j++;
                    count++;
                }
                cur += to_string(count) + pre[j];
                count = 1;
            }

            result = cur;
        }

        return result;
    }
};

int main(){
    Solution s;
    cout << s.countAndSay(7);
}