//
// Created by zqn on 2019/4/20.
//

//
// Created by zqn on 2019/4/8.
//

//给定一个列表，将有重叠部分的合并。例如[ [ 1 3 ] [ 2 6 ] ] 合并成 [ 1 6 ] 。

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals) {

    int size = intervals.size();
    if(size <= 1){
        return intervals;
    }

    sort(intervals.begin(),intervals.end(),[](vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    });

    vector<vector<int>> result;

    result.push_back(intervals[0]);

    for(int i = 1; i <= size; i++){
        vector<int> newone = result.back();
        if(newone[1] >= intervals[i][0]){
            result.pop_back();
            newone[1]  = max(newone[1] , intervals[i][1]);
            result.push_back(newone);
        }
        else{
            result.push_back(intervals[i]);
        }
    }
    return result;

}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> results;

        sort(intervals.begin(), intervals.end(), [](auto& i1, auto& i2){return i1[0]<i2[0];});

        for (int i = 0; i < intervals.size(); ++i) {
            // Can't overlap case
            if (i+1 == intervals.size()) {
                results.push_back(intervals[i]);
                continue;
            }

            int& lo1 = intervals[i][0];
            int& hi1 = intervals[i][1];
            int& lo2 = intervals[i+1][0];
            int& hi2 = intervals[i+1][1];

            // Not overlapping case
            if (lo2 > hi1) {
                results.push_back(intervals[i]);
                continue;
            }

            // Overlaps
            lo2 = lo1;
            hi2 = max(hi1,hi2);
        }

        return results;
    }
};

int main(){
    vector<vector<int>> intervals = {{1,3}, {2,6}, {6,10}, {15,18}};
    vector<vector<int>> result = merge(intervals);
    return 0;
}