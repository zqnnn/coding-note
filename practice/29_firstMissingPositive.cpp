//
// Created by zqn on 2019/4/2.
//



#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//题目描述：
//
//给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
//
//示例 1:
//
//输入: [1,2,0]
//输出: 3
//示例 2:
//
//输入: [3,4,-1,1]
//输出: 2
//示例 3:
//
//输入: [7,8,9,11,12]
//输出: 1
//说明:
//
//你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。


//用了排序，虽然过了，但是时间复杂度超了
//class Solution {
//public:
//    int firstMissingPositive(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int small = 1;
//        for(int i = 0; i < nums.size(); i++){
//            if(small < nums[i]){
//                return small;
//            }
//            else if(small == nums[i]){
//                small++;
//                continue;
//            }
//            else{
//                continue;
//            }
//
//        }
//
//        return small;
//
//    }
//};

//本质上是桶排序 (bucket sort)，每当 A[i]!= i+1 的时候，将 A[i] 与 A[A[i]-1] 交换，直到无法
//交换为止，终止条件是 A[i]== A[A[i]-1]。
//代码
//// LeetCode, First Missing Positive
//// 时间复杂度 O(n)，空间复杂度 O(1)

//1）交换的过程不是一次完成的，而是一个循环过程。
//
//（2）终止循环的条件有以下三个：
//
//a.当nums[i] <= 0时，我们应该终止循环，因为我们不知道这个值应该放在哪里。
//
//b.当nums[i] > nums.length时，我们应该终止循环，因为我们不知道这个值应该放在哪里。
//
//c.当nums[nums[i] - 1] == nums[i]时，我们应该终止循环，因为此时数组中索引为i的位置已经存放了正确的数。
//
//（3）交换过程结束之后，遍历nums数组，寻找第一个nums[i]不等于i + 1的位置，返回即可。如果遍历完整个数组都没有找到，则说明该数组中的元素是[1, 2, 3, 4, ...]的一个排列形式，我们应该返回nums.length + 1。

class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            bucket_sort(A, n);
            for (int i = 0; i < n; ++i)
                if (A[i] != (i + 1))
                    return i + 1;
        return n + 1;
        }
    private:
        static void bucket_sort(int A[], int n) {
            for (int i = 0; i < n; i++) {
                while (A[i] != i + 1) {
                    if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
                        break;
                    swap(A[i], A[A[i] - 1]);
                }
            }
        }
};

int main(){

    //使用键盘读取一行已知个数的数字并存入vector中
    vector<int> v;
    int num;
    cin >> num;
    int a;
    for(int i = 0; i < num; i++){
        cin >> a;
        v.push_back(a);
    }

    Solution s;
    int small = s.firstMissingPositive(v);
    cout << small;
}