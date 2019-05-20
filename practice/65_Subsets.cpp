//
// Created by zqn on 2019/5/20.
//
#include <vector>
using namespace std;
//LeetCode（78）：子集
//Medium！
//
//题目描述：
//
//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//
//说明：解集不能包含重复的子集。
//
//示例:
//
//输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//]
//解题思路：
//非递归的解法
//最开始是想按照子集的长度由少到多全部写出来，
// 比如子集长度为0的就是空集，空集是任何集合的子集，满足条件，直接加入。
// 下面长度为1的子集，直接一个循环加入所有数字，
// 子集长度为2的话可以用两个循环，但是这种想法到后面就行不通了，
// 因为循环的个数不能无限的增长，所以我们必须换一种思路。

//我们可以一位一位的往上叠加，比如对于题目中给的例子[1,2,3]来说，最开始是空集，
// 那么我们现在要处理1，就在空集上加1，为[1]，现在我们有两个自己[]和[1]，
// 下面我们来处理2，我们在之前的子集基础上，每个都加个2，可以分别得到[2]，[1, 2]，那么现在所有的子集合为[], [1], [2], [1, 2]，
// 同理处理3的情况可得[3], [1, 3], [2, 3], [1, 2, 3], 再加上之前的子集就是所有的子集合了。

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1); //1代表空集
        int length = nums.size();
        for(int i = 0; i < length; i++){
            int size = res.size();
            for(int j = 0; j < size; j++){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};

//递归的解法，相当于一种深度优先搜索
//由于原集合每一个数字只有两种状态，要么存在，要么不存在，那么在构造子集时就有选择和不选择两种情况，所以可以构造一棵二叉树，
// 左子树表示选择该层处理的节点，右子树表示不选择，最终的叶节点就是所有子集合，树的结构如下：
//                        []
//                   /          \
//                  /            \
//                 /              \
//              [1]                []
//           /       \           /    \
//          /         \         /      \
//       [1 2]       [1]       [2]     []
//      /     \     /   \     /   \    / \
//  [1 2 3] [1 2] [1 3] [1] [2 3] [2] [3] []

void getSubsets(vector<int> &nums, int pos, vector<int> &out, vector<vector<int>> &res){
    res.push_back(out);
    for(int i = pos; i < nums.size(); i++){
        out.push_back(nums[i]);
        getSubsets(nums, i+1, out, res);
        out.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> out;
    getSubsets(nums, 0, out, result);
    return result;
}


int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = subsets(nums);
    return 0;
}
