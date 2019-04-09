//
// Created by zqn on 2019/3/16.
//



//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
//
//## 解题思路
//
//遇到这个题，全排列当然可以做，但是时间复杂度为O(n!)。在这里我们自己定义一个规则，对拼接后的字符串进行比较。
//
//排序规则如下：
//- 若ab > ba 则 a 大于 b，
//- 若ab < ba 则 a 小于 b，
//- 若ab = ba 则 a 等于 b；
//
//根据上述规则，我们需要先将数字转换成字符串再进行比较，因为需要串起来进行比较。比较完之后，按顺序输出即可。


#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string answer = "";
        if(numbers.size() == 0) return {};
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i = 0; i < numbers.size(); i++){
            answer += to_string(numbers[i]);
        }
        return answer;
    }

    //
    // 必须加static
    // 问题的原因其实就是函数参数不匹配的问题。
    // 因为我们普通的成员函数都有一个隐含的this指针，表面上看我们的谓词函数cmp（）只有两个参数，但实际上它有三个参数，
    // 而我们调用sort（）排序函数的时候只需要用到两个参数进行比较，所以就出现了形参与实参不匹配的情况（函数有三个形参，但是只输入了两个实参）。
    //所以，解决办法就是把谓词函数cmp（）定义为static成员函数。

    static bool cmp(int a, int b){
        string A = "";
        string B = "";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A < B;
    }
};

int main(){
    Solution s;
    vector<int> numbers = {12, 113, 15 };
    string a = s.PrintMinNumber(numbers);
    std::cout << a << std::endl;
}