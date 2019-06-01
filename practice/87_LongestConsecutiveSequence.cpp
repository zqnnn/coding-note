//
// Created by zqn on 2019/6/1.
//

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;
//给定一个未排序的整数数组，找出最长连续序列的长度。
//
//要求算法的时间复杂度为 O(n)。
//
//示例:
//
//输入: [100, 4, 200, 1, 3, 2]
//输出: 4
//解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

//这道题要求求最长连续序列，并给定了O(n)复杂度限制，
// 我们的思路是，使用一个集合HashSet存入所有的数字，
// 然后遍历数组中的每个数字，如果其在集合中存在，那么将其移除，
// 然后分别用两个变量pre和next算出其前一个数跟后一个数，
// 然后在集合中循环查找，如果pre在集合中，那么将pre移除集合，然后pre再自减1，直至pre不在集合之中，
// 对next采用同样的方法，那么next-pre-1就是当前数字的最长连续序列，更新res即可。
// 这里再说下，为啥当检测某数字在集合中存在当时候，都要移除数字。
// 这是为了避免大量的重复计算，就拿题目中的例子来说吧，我们在遍历到4的时候，会向下遍历3，2，1，
// 如果都不移除数字的话，遍历到1的时候，还会遍历2，3，4。
// 同样，遍历到3的时候，向上遍历4，向下遍历2，1，等等等。
// 如果数组中有大量的连续数字的话，那么就有大量的重复计算，十分的不高效，
// 所以我们要从HashSet中移除数字，代码如下：
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(int val: nums){
            if(!s.count(val)) continue;
            s.erase(val);
            int pre = val - 1, next = val + 1;
            while (s.count(pre)) s.erase(pre--);
            while (s.count(next)) s.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
    }
};


//我们也可以采用哈希表来做，刚开始HashMap为空，然后遍历所有数字，
// 如果该数字不在HashMap中，那么我们分别看其左右两个数字是否在HashMap中，
// 如果在，则返回其哈希表中映射值，若不在，则返回0
//虽然我们直接从HashMap中取不存在的映射值，也能取到0，
// 但是一旦去取了，就会自动生成一个为0的映射，
// 那么我们这里再for循环的开头判断如果存在映射就跳过的话，就会出错。

//然后我们将left+right+1作为当前数字的映射，并更新res结果，同时更新num-left和num-right的映射值。
int longestConsecutive(vector<int>& nums){
    int res = 0;
    unordered_map<int, int> map;
    for(int val: nums){
        if(map.count(val)) continue;
        int left = map.count(val-1) ? map[val-1] : 0;
        int right = map.count(val+1) ? map[val+1] : 0;
        int sum = left + right + 1;
        map[val] = sum;
        res = max(res, sum);
        map[val - left] = sum;
        map[val + left] = sum;
    }
    return res;
}


int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums);
}