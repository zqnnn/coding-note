//
// Created by zqn on 2019/3/25.
//


#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


//暴力方法
//循环两遍
//vector<int> twoSum(vector<int>& nums, int target) {
//    vector<int> result;
//    for(int i = 0; i < nums.size()-1; i++){
//        int leftnum = target - nums[i];
//        for(int j = i+1; j < nums.size(); j++){
//            if(leftnum == nums[j]){
//                result.push_back(i);
//                result.push_back(j);}
//        }
//    }
//
//    return result;
//}

//一般来说，我们为了提高时间的复杂度，需要用空间来换，这算是一个trade off吧，
// 我们只想用线性的时间复杂度来解决问题，那么就是说只能遍历一个数字，那么另一个数字呢，
// 我们可以事先将其存储起来，使用一个HashMap，来建立数字和其坐标位置之间的映射，
// 我们都知道HashMap是常数级的查找效率，这样，我们在遍历数组的时候，用target减去遍历到的数字，
// 就是另一个需要的数字了，直接在HashMap中查找其是否存在即可，注意要判断查找到的数字不是第一个数字，
// 比如target是4，遍历到了一个2，那么另外一个2不能是之前那个2，整个实现步骤为：先遍历一遍数组，建立HashMap映射，然后再遍历一遍，
// 开始查找，找到则记录index。


vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> mapping;
    vector<int> result;

    //建立一个哈希表， 存储每个数对应的下标
    for(int i = 0; i < nums.size(); i++){
        mapping[nums[i]] = i;
    }

    //循环计算
    for(int i = 0; i < nums.size(); i++){
        const int gap = target - nums[i];
        if(mapping.count(gap) && mapping[gap] > i) {
            result.push_back(i);
            result.push_back(mapping[gap]);
        }

    }

    return result;
}

int main(){
    vector<int > nums = {1,2,3,4};
    int t = 3;
    vector<int > sum = twoSum(nums, t);
    for(int i = 0; i < sum.size(); i++)
        cout<<sum[i]<<endl;
}