//
// Created by zqn on 2019/5/22.
//
#include <vector>
#include <iostream>
#include <stack>
using namespace std;


//这道题让求直方图中最大的矩形，
// 这里有一种很好的优化方法，
// 就是遍历数组，每找到一个局部峰值，
// 然后向前遍历所有的值，算出共同的矩形面积，
// 每次对比保留最大值。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for(int i = 0; i < heights.size(); i++){
            if(i+1 < heights.size() && heights[i] <= heights[i+1]){
                continue;
            }
            int minH = heights[i];
            for(int j = i; j >= 0; j--){
                minH = min(minH, heights[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }
};

//还有一种比较流行的解法，是利用栈来解，
// 这里维护一个栈，用来保存递增序列，相当于上面那种方法的找局部峰值。
//我们可以看到，直方图形面积要最大的话，需要尽可能的使用连续的矩形多，并且最低一块的高度要高。
// 有点要木桶原理一样，总是最低的那块板子决定桶的装水量。
// 那么既然需要用单调栈来做，首先要考虑到底用递增栈，还是用递减栈来做。
//增栈是维护递增的顺序，当遇到小于栈顶元素的数就开始处理，
// 而递减栈正好相反，维护递减的顺序，当遇到大于栈顶元素的数开始处理。

//。那么根据这道题的特点，我们需要按从高板子到低板子的顺序处理，先处理最高的板子，宽度为1，
// 然后再处理旁边矮一些的板子，此时长度为2，
// 因为之前的高板子可组成矮板子的矩形 ，因此我们需要一个递增栈，
// 当遇到大的数字直接进栈，而当遇到小于栈顶元素的数字时，就要取出栈顶元素进行处理了，
// 那取出的顺序就是从高板子到矮板子了，
// 于是乎遇到的较小的数字只是一个触发，表示现在需要开始计算矩形面积了，为了使得最后一块板子也被处理，
// 这里用了个小trick，在高度数组最后面加上一个0，这样原先的最后一个板子也可以被处理了。

//由于栈顶元素是矩形的高度，那么关键就是求出来宽度，那么跟之前那道Trapping Rain Water一样，
// 单调栈中不能放高度，而是需要放坐标。
// 由于我们先取出栈中最高的板子，那么就可以先算出长度为1的矩形面积了，然后再取下一个板子，
// 此时根据矮板子的高度算长度为2的矩形面积，以此类推，直到数字大于栈顶元素为止，再次进栈，很是巧妙！


int largestRectangleArea(vector<int> &height){
    int res = 0;
    stack<int> st;
    height.push_back(0);//在高度数组最后面加上一个0，这样原先的最后一个板子也可以被处理了。
    for(int i = 0; i < height.size(); i++){
        while (!st.empty() && height[st.top()] >= height[i]){
            int cur = st.top();
            st.pop();
            res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
        }
        st.push(i);
    }

    return res;
}
int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution s;
    cout << s.largestRectangleArea(heights) << endl;

    cout << largestRectangleArea(heights);
}