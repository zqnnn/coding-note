//
// Created by zhangqianni on 2019-08-07.
//

//求最大子数组乘积
//Example 1:
//
//Input: [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//Example 2:
//
//Input: [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include <vector>
#include <iostream>
using namespace std;


//这个求最大子数组乘积问题是由最大子数组之和问题演变而来，但是却比求最大子数组之和要复杂，
// 因为在求和的时候，遇到0，不会改变最大值，遇到负数，也只是会减小最大值而已。
// 而在求最大子数组乘积的问题中，遇到0会使整个乘积为0，而遇到负数，则会使最大乘积变成最小乘积，
// 正因为有负数和0的存在，使问题变得复杂了不少。
// 比如，我们现在有一个数组[2, 3, -2, 4]，我们可以很容易的找出所有的连续子数组，
// [2], [3], [-2], [4], [2, 3], [3, -2], [-2, 4], [2, 3, -2], [3, -2, 4], [2, 3, -2, 4],
// 然后可以很轻松的算出最大的子数组乘积为6，来自子数组[2, 3].
//
//那么我们如何写代码来实现自动找出最大子数组乘积呢，我最先想到的方比较简单粗暴，就是找出所有的子数组，然后算出每一个子数组的乘积，然后比较找出最大的一个，
// 需要两个for循环，第一个for遍历整个数组，第二个for遍历含有当前数字的子数组，
// 就是按以下顺序找出子数组: [2], [2, 3], [2, 3, -2], [2, 3, -2, 4],    [3], [3, -2], [3, -2, 4],    [-2], [-2, 4],    [4],
// 我在本地测试的一些数组全部通过，于是兴高采烈的拿到OJ上测试，结果丧心病狂的OJ用一个有15000个数字的数组来测试，然后说我程序的运行时间超过了要求值，
// 我一看我的代码，果然如此，时间复杂度O(n2), 得想办法只用一次循环搞定。我想来想去想不出好方法，于是到网上搜各位大神的解决方法。
//
// 其实这道题最直接的方法就是用DP来做，而且要用两个dp数组，其中f[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最大子数组乘积，
// g[i]表示子数组[0, i]范围内并且一定包含nums[i]数字的最小子数组乘积，初始化时f[0]和g[0]都初始化为nums[0]，其余都初始化为0。
// 那么从数组的第二个数字开始遍历，那么此时的最大值和最小值只会在这三个数字之间产生，即f[i-1]*nums[i]，g[i-1]*nums[i]，和nums[i]。
// 所以我们用三者中的最大值来更新f[i]，用最小值来更新g[i]，然后用f[i]来更新结果res即可，
// 由于最终的结果不一定会包括nums[n-1]这个数字，所以f[n-1]不一定是最终解，不断更新的结果m才是，参见代码如下：

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int m = nums[0];
        int n = nums.size();
        vector<int>  f(n, 0), g(n, 0);
        f[0] = nums[0]; // 保存最大值
        g[0] = nums[0]; // 保存最小值

        for(int i = 1; i < n; i++){
            int tmp1 = f[i-1] * nums[i];
            int tmp2 = g[i-1] * nums[i];
            f[i] = max(max(tmp1, tmp2), nums[i]);
            g[i] = min(min(tmp1, tmp2), nums[i]);

            m = max(m, f[i]);
        }

        return m;
    }
};


int main(){
    int temp;
    vector<int> input;
    for(int i = 0; ; i++){
        cin >> temp;
        input.push_back(temp);
        if(getchar() == '\n')
            break;
    }
    Solution s;
    cout << s.maxProduct(input);
}