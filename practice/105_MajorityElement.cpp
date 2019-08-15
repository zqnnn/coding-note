//
// Created by zhangqianni on 2019-08-15.
//

//求大多数
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        unordered_map<int, int>::iterator iter = map.begin();
        int maxnum = 0, cnt = 0;
        while (iter != map.end()){
            if(iter->second > cnt){
                maxnum = iter->first;
                cnt = iter->second;
            }
            iter++;
        }
        return maxnum;
    }
};


int main(){
    vector<int> num = {1,2,3,4,1,2,1,1};
    Solution s;
    cout << s.majorityElement(num);

}