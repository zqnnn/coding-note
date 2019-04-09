//
// Created by zqn on 2019/3/26.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//问题：求数组中，所有和为0 的三个元素。
//
//解题思路：
//
//自己想了一个解法，但是扔上去超时了，然后在网上看到使用双指针的算法，理解后，把这道题解决了。
//
//第一步，对数组排序。
//
//
//
//第二步，
//
//分析1：对于元素 S[i] ， 最后的答案可以分为两种，包含 S[i] 的，和不包含 S[i] 的。当包含 S[i] 的情况都找到后，后续就可以不用在考虑 S[i] 。
//
//对于 S[i] ， l = i+1, r = len-1 。若 s[i] + S[l] + S[r] == 0， 则为原问题的一个解。
//
//当 S[i] + S[l] > -S[r] 时，则 r--
//当 S[i] + S[l] < -S[r] 时，则 l++
//当 S[i] + S[i] = -S[r] 时， 表示是原问题的一个解，则 l++, r--;
//第三步，性能优化。同样根据分析1，若 S[i] == S[i+1]，可以跳过。


vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> results;
    if(nums.size() < 3)
        return results;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i-1]) continue; //去重
        int target = 0 - nums[i];
        int l = i + 1;
        int r = nums.size() - 1;
        while(l < r){
            if(nums[i] + nums[l] > -nums[r]){
                r--;
            }
            else if(nums[i] + nums[l] < -nums[r]){
                l++;
            }
            else{
                results.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l + 1]) l++;
                while (l < r && nums[r] == nums[r - 1]) r--;
                l++;
                r--;
            }
        }
    }
    return results;

}


int main(){
    vector<int> nums = {-2,0,0,2,2};
    vector<int> result;
    vector<vector<int>> results = threeSum(nums);
    for(int i =0; i < results.size(); i++){
        result = results[i];
        for(int j = 0; j < result.size(); j++){
            int x = result[j];
            cout << x << endl;
        }
    }
    return 0;

}