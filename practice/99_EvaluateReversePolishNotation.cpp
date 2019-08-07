//
// Created by zhangqianni on 2019-08-07.
//

//计算逆波兰表达式
//Example 1:
//
//Input: ["2", "1", "+", "3", "*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9
//Example 2:
//
//Input: ["4", "13", "5", "/", "+"]
//Output: 6
//Explanation: (4 + (13 / 5)) = 6
//Example 3:
//
//Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//Output: 22
//Explanation:
//  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22

//逆波兰表达式就是把操作数放前面，把操作符后置的一种写法


#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) return stoi(tokens[0]);
        stack<int> s1;

        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                s1.push(stoi(tokens[i]));
            }
            else{
                int a1 = s1.top();
                s1.pop();
                int a2 = s1.top();
                s1.pop();
                if(tokens[i] == "+") s1.push(a2 + a1);
                if(tokens[i] == "-") s1.push(a2 - a1);
                if(tokens[i] == "*") s1.push(a2 * a1);
                if(tokens[i] == "/") s1.push(a2 / a1);

            }
        }
        return s1.top();
    }
};


int main(){
    vector<string> token = {"0", "3", "/"};
    Solution s;
    cout << s.evalRPN(token);
    return 0;
}