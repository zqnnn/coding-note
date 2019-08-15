//
// Created by zhangqianni on 2019-08-15.
//

//给定表示分数的分子和分母的两个整数，以字符串格式返回分数。 如果小数部分重复，则将重复部分括在括号中

//分析：这里面需要考虑下面几个问题：
//1、如何循环求数？
//2、如何判断重复？
//3、如何结束循环？
//4、会不会溢出？

//对于第一个问题：如果直接除数除以被除数，然后去逐位来找，那样的话是非常难以实现的（即使可以实现，那找循环体简直变成了不可能事件）。
// 那换个思路，我们每次都作除，然后取整数部分，然后余数*10，继续下去。这样就简单多了，因为取整是非常简单的（强制类型转换即可）。

//第二个问题：如何判断重复，对于这种思路而言，当除数在以前的历史中出现过，就可以判断剩下的数据也会不断重复。
// 因此，我们可以存一个hashmap，key就是出现的除数，然后value就是结果数组的index值。只要包含该key时，就可以停止了。

//第三个问题：已经回答了，只要包含有key或者除数为0时就可以停止了。

//第四个问题：溢出怎么办？对待溢出最简单的解决方案是将其转换为更大的类型。

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";

        long long num = numerator;
        long long deno = denominator;
        num = abs(num);
        deno = abs(deno);

        string res;
        if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) res += '-';

        res += to_string(num / deno);
        if(num % deno == 0)
            return res;

        res += '.';
        unordered_map<int, int> map;

        long long sub = num % deno;

        while (sub){
            if(map.count(sub) > 0){
                res.insert(map[sub], 1, '(');
                res += ')';
                break;
            }
            else{
                map[sub] = res.size();
                sub = sub * 10;
                res += to_string(sub / deno);
                sub = sub % deno;
            }
        }

        return res;
    }
};