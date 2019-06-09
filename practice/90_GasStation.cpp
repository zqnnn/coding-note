//
// Created by zqn on 2019/6/9.
//


//在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//
//如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
//
//说明: 
//
//如果题目有解，该答案即为唯一答案。
//输入数组均为非空数组，且长度相同。
//输入数组中的元素均为非负数。
//

//解题思路：
//
//1.对站点进行遍历，从每个站点出发一次，看从该站点出发能不能跑完整个环。该思路会超时。
//
//2.考虑该问题的规律和特征。有两个特征：a.若sum(gas)<sum(cost)，则返回值为-1.

//  b.若从0-n的sum(gas)<sum(cost),则n以前的所有站点都不能作为起始站点。

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0, start = 0, total = 0;
        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(res + gas[i] - cost[i] < 0){
                start = i+1;
                res = 0;
            }
            else{
                res += gas[i] - cost[i];
            }
        }
        return (total < 0) ? -1 : start;
    }
};


int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    Solution s;
    cout << s.canCompleteCircuit(gas, cost);
}