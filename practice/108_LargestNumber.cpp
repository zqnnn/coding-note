//
// Created by zhangqianni on 2019-08-16.
//

//最大组合数
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//这道题给了我们一个数组，让我们将其拼接成最大的数，那么根据题目中给的例子来看，主要就是要给给定数组进行排序，
// 但是排序方法不是普通的升序或者降序，因为9要排在最前面，而9既不是数组中最大的也不是最小的，所以我们要自定义排序方法。
// 如果不参考网友的解法，我估计是无法想出来的。
// 这种解法对于两个数字a和b来说，如果将其都转为字符串，如果ab > ba，则a排在前面，比如9和34，由于934>349，所以9排在前面，
// 再比如说30和3，由于303<330，所以3排在30的前面。按照这种规则对原数组进行排序后，
// 将每个数字转化为字符串再连接起来就是最终结果。代码如下：

class Solution {
public:
    //写在类内时，cmp函数需要是静态函数，要加上static。
    static bool cmp(int a, int b){
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

    string largestNumber(vector<int>& nums) {
        string s;
        sort(nums.begin(), nums.end(), cmp);

        for(int i = 0; i < nums.size(); i++){
            s += to_string(nums[i]);
        }
        return s[0] == '0' ? "0" : s;

    }
};