//
// Created by zqn on 2019/5/17.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)
            return x;
        int left = 0, right = x;
        while (left < right){
            int mid = (left + right) / 2;
            if(x / mid >= mid) left = mid + 1;
            else right = mid;
        }
        return right-1;

    }

};


int find(vector<int> &nums, int target){
    int left = 0, right = nums.size();
    while (left < right){
        int mid = (left + right) / 2;
        if(nums[mid] <= target){
            left = mid + 1;
        } else
            right = mid;
    }
    return right-1;
}


int main(){
    vector<int> a = {2,4,5,6,9};
    cout << find(a, 6);
}