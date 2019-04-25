//
// Created by zqn on 2019/4/25.
//
#include <algorithm>
#include <limits.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            if(abs(res) > INT_MAX / 10)
                return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

int main(){
    int a = 34234;
    Solution s;
    cout << s.reverse(a);
}