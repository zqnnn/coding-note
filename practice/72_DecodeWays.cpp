//
// Created by zqn on 2019/5/23.
//


#include <iostream>
#include <string>
#include <vector>
using namespace std;

//91. Decode Ways
//题目大意
//将大写字母串加密，有如下映射：
//
//‘A’ -> 1
//‘B’ -> 2
//…
//‘Z’ -> 26

//现给出一串加密过的数字串，要求求出该串能解密出的不同大写字母串的数目。
//
//例
//“12”-> “AB” (1 2) or “L” (12).
//ans:2

//建立一位dp数组，长度比输入数组长度多2，全部初始化为1，因为斐波那契数列的前两项也为1，
// 然后从第三个数开始更新，对应数组的第一个数。
// 对每个数组首先判断其是否为0，若是将改为dp赋0，
// 若不是，赋上一个dp值，此时相当如加上了dp[i - 1],
// 然后看数组前一位是否存在，如果存在且满足前一位不是0，且和当前为一起组成的两位数不大于26，
// 则当前dp值加上dp[i - 2], 至此可以看出来跟斐波那契数组的递推式一样。


class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int> dp(s.size(), 0);

        //dp[0]
        if(s[0] == '0'){
            dp[0] = 0;
        } else dp[0] = 1;

        //dp[1]
        if(s.size() > 1){
            if(s[0] == '0'){
                dp[1] = 0;
            }
            else if(s[0] == '1'){
                if(s[1] == '0'){
                    dp[1] = 1;
                } else{
                    dp[1] = 2;
                }
            }
            else if(s[0] == '2'){
                if(s[1] >= '1' && s[1] <= '6'){
                    dp[1] = 2;
                }
                else{
                    dp[1] = 1;
                }
            }
            //   // 30,40...
            else if(s[1] == '0'){
                dp[1] = 0;
            }
            else{
                dp[1] = 1;
            }
        }

        for(int i = 2; i < s.size(); i++){
            if(s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2'){
                    dp[i] = dp[i-2];
                } else
                    dp[i] = 0;
            }

            else if(s[i-1] == '1' || (s[i-1] == '2' && (s[i] >= '1' && s[i] <='6'))){
                dp[i] = dp[i-2] + dp[i-1];
            }

            else
                dp[i] = dp[i-1];
        }

        return dp.back();

    }
};