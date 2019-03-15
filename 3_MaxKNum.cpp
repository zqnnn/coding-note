//
// Created by zqn on 2019/3/14.
//

//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


//方法一
//1.取数组前K个元素建最大堆。
//
//2。将数组剩余元素一次与最大堆堆顶元素比较，如果比堆顶元素小，则删除堆顶元素，该元素入堆。
//vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//    if(input.size() == 0 || input.size() < k || k <= 0)
//        return {};
//    vector<int> res(input.begin(), input.begin()+k);
//    make_heap(res.begin(), res.end());
//    for(int i = k; i < input.size(); i++){
//        if(input[i] < res[0]){
//            pop_heap(res.begin(), res.end());
//            res.pop_back();
//            res.push_back(input[i]);
//            push_heap(res.begin(), res.end());
//        }
//    }
//    sort_heap(res.begin(), res.end());
//    return res;
//}












class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size()==0 || input.size()<k || k<=0)
            return {};

        int low = 0;
        int high = input.size()-1;
        int index = Partition(input, low, high);

        while(index != k-1){
            if(index > k-1){
                high = index - 1;
                index = Partition(input, low, high);
            }
            else{
                low = index + 1;
                index = Partition(input, low, high);
            }
        }
        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(input[i]);
        }

        return result;
    }


//    int partion(vector<int>& input, int beg, int end)
//    {
//        int key = input[beg];
//        while (beg < end)
//        {
//            while (beg < end && input[end] >= key)end--;
//            input[beg] = input[end];
//            while (beg < end && input[beg] <= key)beg++;
//            input[end] = input[beg];
//        }
//        input[beg] = key;
//        return beg;
//    }


    int Partition(vector<int> &input, int low, int high){
        int x0 = input[low];
        while(low < high){
            while(low < high && x0 <= input[high]){
                high--;
            }
            input[low] = input[high];

            while(low < high && x0 >= input[low]){
                low++;
            }
            input[high] = input[low];
        }
        input[low] = x0;
        return low;
    }
};


int main(){
    vector<int> input = {2,1,3,2,1,4,2};
    Solution solution;
    vector<int> result;
    result = solution.GetLeastNumbers_Solution(input, 3);
    for(int i = 0; i < result.size(); i++){
        cout << result[i];
    }
}