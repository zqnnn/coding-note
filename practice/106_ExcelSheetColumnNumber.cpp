//
// Created by zhangqianni on 2019-08-15.
//

//求Excel表列序号

//这题实际上相当于一种二十六进制转十进制的问题，并不难，只要一位一位的转换即可。
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int titleToNumber(string s) {
        int length = s.length();
        int res = 0;
        for(int i = 0; i < length; i++){
            int cur = s[i] - 'A' + 1;
            res = res * 26 + cur;
        }
        return res;

    }
};

int main(){
    string s = "ZY";
    Solution solution;
    cout << solution.titleToNumber(s);
}