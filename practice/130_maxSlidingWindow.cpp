//
// Created by zqn on 2019/9/4.
//
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

//简单粗暴型。。竟然过了
class Solution {
public:
    int max_num(vector<int>& nums, int i, int j){
        int max_res = 0;
        for(int q = i; q < j; q++){
            max_res = max(max_res, nums[q]);
        }
        return max_res;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k == 0)
            return {};
        if(k == 1)
            return nums;
        vector<int> res;
        int i = 0, size = nums.size();
        while (i <= size - k){
            int max = max_num(nums, i, i+k);
            res.push_back(max);
            i++;
        }
        return res;
    }
};

//我们希望窗口内的数字是有序的，但是每次给新窗口排序又太费时了，所以最好能有一种类似二叉搜索树的结构，
// 可以在 lgn 的时间复杂度内完成插入和删除操作，
// 那么使用 STL 自带的 multiset 就能满足我们的需求，这是一种基于红黑树的数据结构，
// 可以自动对元素进行排序，又允许有重复值，完美契合。
//遍历每个数字，即窗口右移，若超过了k，则需要把左边界值删除，这里不能直接删除 nums[i-k]，
// 因为集合中可能有重复数字，我们只想删除一个，而 erase 默认是将所有和目标值相同的元素都删掉，
// 所以我们只能提供一个 iterator，代表一个确定的删除位置，先通过 find() 函数找到左边界 nums[i-k] 在集合中的位置，
// 再删除即可。然后将当前数字插入到集合中，此时看若 i >= k-1，说明窗口大小正好是k，
// 就需要将最大值加入结果 res 中，而由于 multiset 是按升序排列的，最大值在最后一个元素，我们可以通过rbegin() 来取出

vector<int> maxSlidingwindow(vector<int> &nums, int k){
    vector<int> res;
    multiset<int> st;
    for(int i = 0; i < nums.size(); i++){
        if(i >= k) st.erase(st.find(nums[i-k]));
        st.insert(nums[i]);
        if(i >= k-1) res.push_back(*st.rbegin());
    }
    return res;

}


//我们也可以使用优先队列来做，即最大堆，不过此时我们里面放一个 pair 对儿，由数字和其所在位置组成的，
// 这样我们就可以知道每个数字的位置了，而不用再进行搜索了。在遍历每个数字时，进行 while 循环，
// 假如优先队列中最大的数字此时不在窗口中了，就要移除，判断方法就是将队首元素的 pair 对儿中的 second（位置坐标）跟 i-k 对比，
// 小于等于就移除。然后将当前数字和其位置组成 pair 对儿加入优先队列中。
// 此时看若 i >= k-1，说明窗口大小正好是k，就将最大值加入结果 res 中即可，参见代码如下：

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    priority_queue<pair<int, int>> q; //默认是大顶堆
    for(int i = 0; i < nums.size(); i++){
        while (!q.empty() && q.top().second <= i-k) q.pop();
        q.push({nums[i], i});
        if(i >= k-1) res.push_back(q.top().first);
    }
    return res;
}

int main(){
    vector<int> num = {1,-1};
    maxSlidingwindow(num, 1);
}