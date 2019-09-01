//
// Created by zqn on 2019/9/1.
//


//实现一个计算器，包含非负数加减乘除

#include <string>
#include <stack>
#include <iostream>
using namespace std;

//由于存在运算优先级，我们采取的措施是使用一个栈保存数字，如果该数字之前的符号是加或减，那么把当前数字压入栈中，注意如果是减号，
// 则加入当前数字的相反数，因为减法相当于加上一个相反数。如果之前的符号是乘或除，
// 那么从栈顶取出一个数字和当前数字进行乘或除的运算，再把结果压入栈中，那么完成一遍遍历后，
// 所有的乘或除都运算完了，再把栈中所有的数字都加起来就是最终结果了。
class Solution {
public:
    int calculate(string s) {
        long res = 0, num = 0, size = s.size();
        char c = '+';
        stack<int> st;
        for(int i = 0; i < size; i++){
            if(s[i] >= '0'){ //可能是多位数
                num = num * 10 + s[i] - '0';
            }
            if((s[i] < '0' && s[i] != ' ') || i == size-1){
                if(c == '+') st.push(num);
                if(c == '-') st.push(-num);
                if(c == '/' || c == '*'){
                    int a = st.top();
                    int tmp = 0;
                    if(c == '*') tmp = num * a;
                    else tmp = a / num;
                    st.pop();
                    st.push(tmp);
                }
                c = s[i];
                num = 0;
            }
        }

        while (!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};



int main(){
    string s = "3+2*2";
    Solution s0;
    cout << s0.calculate(s);
}