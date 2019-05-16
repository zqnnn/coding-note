//
// Created by zqn on 2019/5/16.
//

#include <vector>
#include <iostream>
using namespace std;

//递归法
//全排列问题
//
//比如给个数字 123 如何将他们进行 全排列
//我们这里用到了递归的思考 
//比如1跟2先调换  213  然后 1 跟 3 重新进行全排列,然后再调换回来
//swap(p[0],p[1]);
//permutations(p,1,2);
//swap(p[0],p[1]);
//然后1 跟 3 调换 变成 321 然后 2跟1重新进行全排列
//swap(p[0],p[2]);
//permutations(p,1,2);
//swap(p[0],p[2]);
//假如说我们在第一次的时候 设1跟1它自己本身调换，也就有了
//swap(p[0],p[0]);
//permutations(p,1,2);
//
//swap(p[0],p[0]);
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutationrecursive(nums, 0, result);
        return result;
    }

    void permutationrecursive(vector<int> &nums, int k, vector<vector<int>> &result){
        if(k == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int i = k; i < nums.size(); i++){
            cout << "i=" << i << "," << "k=" << k << endl;
            cout <<  "swap前" << nums[0] << "," << nums[1] << "," << nums[2] << endl;
            swap(nums[i], nums[k]);
            cout << "swap后" << nums[0] << "," << nums[1] << "," << nums[2] << endl;
            permutationrecursive(nums, k+1, result);
            cout << "递归后" << nums[0] << "," << nums[1] << "," << nums[2] << endl;
            swap(nums[i], nums[k]);
            cout << "换回来后" << nums[0] << "," << nums[1] << "," << nums[2] << endl;
        }
    }
};

//DFS这道题是求全排列问题，给的输入数组没有重复项，
// 这跟之前的那道 Combinations 和类似，解法基本相同，
// 但是不同点在于那道不同的数字顺序只算一种，是一道典型的组合题，而此题是求全排列问题，
// 还是用递归DFS来求解。
// 这里我们需要用到一个visited数组来标记某个数字是否访问过，
// 然后在DFS递归函数从的循环应从头开始，而不是从level开始，这是和 Combinations 不同的地方，其余思路大体相同。
// 这里再说下level吧，其本质是记录当前已经拼出的个数，
// 一旦其达到了nums数组的长度，说明此时已经是一个全排列了，因为再加数字的话，就会超出。
// 还有就是，为啥这里的level要从0开始遍历，因为这是求全排列，每个位置都可能放任意一个数字，这样会有个问题，数字有可能被重复使用，
// 由于全排列是不能重复使用数字的，
// 所以我们需要用一个visited数组来标记某个数字是否使用过，代码如下：

void permuteDFS(vector<int>& nums, int level, vector<int> &visited, vector<int> &out, vector<vector<int>> &result){
    if(level == nums.size()) result.push_back(out);
    else{
        for(int i = 0; i < nums.size(); i++){
            cout << "i=" << i << endl;
            if(visited[i] == 0){
                visited[i] = 1;
                out.push_back(nums[i]);
                cout <<  "push后=" << out[0] << "," << out[1] << "," << out[2] << endl;
                permuteDFS(nums, level+1, visited, out, result);
                out.pop_back();
                cout <<  "pop后=" << out[0] << "," << out[1] << "," << out[2] << endl;
                visited[i] = 0;
            }
        }
    }

}


//深度优先搜索
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> result;
    vector<int> out;
    vector<int> visited(nums.size(), 0);
    permuteDFS(nums, 0, visited, out, result);
    return result;
}




int main(){
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> result = permute(nums);
    return 0;
}