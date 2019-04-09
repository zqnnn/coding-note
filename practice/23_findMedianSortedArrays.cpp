//
// Created by zqn on 2019/3/25.
//
#include <vector>
#include <iostream>
using namespace std;



//题目描述：
//
//有两个大小为 m 和 n 的排序数组 nums1 和 nums2 。
//
//请找出两个排序数组的中位数并且总的运行时间复杂度为 O(log (m+n))

//这题更通用的形式是，给定两个已经排序好的数组，找到两者所有元素中第 k 大的元素。
//O(m + n) 的解法比较直观，直接 merge 两个数组，然后求第 k 大的元素。
//不过我们仅仅需要第 k 大的元素，是不需要“排序”这么复杂的操作的。可以用一个计数器，
//记录当前已经找到第 m 大的元素了。同时我们使用两个指针 pA 和 pB，分别指向 A 和 B 数组的第
//一个元素，使用类似于 merge sort 的原理，如果数组 A 当前元素小，那么 pA++，同时 m++；如果
//数组 B 当前元素小，那么 pB++，同时 m++。最终当 m 等于 k 的时候，就得到了我们的答案，O(k)
//时间，O(1) 空间。但是，当 k 很接近 m + n 的时候，这个方法还是 O(m + n) 的。

//有没有更好的方案呢？我们可以考虑从 k 入手。如果我们每次都能够删除一个一定在第 k 大元
//素之前的元素，那么我们需要进行 k 次。但是如果每次我们都删除一半呢？由于 A 和 B 都是有序
//的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”

//这里我们需要定义一个函数来找到第K个元素，由于两个数组长度之和的奇偶不确定，因此需要分情况来讨论，
// 对于奇数的情况，直接找到最中间的数即可，偶数的话需要求最中间两个数的平均值。

//下面重点来看如何实现找到第K个元素，首先我们需要让数组1的长度小于或等于数组2的长度，
// 那么我们只需判断如果数组1的长度大于数组2的长度的话，交换两个数组即可，然后我们要判断小的数组是否为空，为空的话，直接在另一个数组找第K个即可。
// 还有一种情况是当K = 1时，表示我们要找第一个元素，只要比较两个数组的第一个元素，返回较小的那个即可。


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        return (findKth(nums1, nums2, (m + n + 1) / 2) + findKth(nums1, nums2, (m + n + 2) / 2)) / 2.0;
    }


    int findKth(vector<int> nums1, vector<int> nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findKth(nums2, nums1, k);
        if (m == 0) return nums2[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);
        int i = min(m, k / 2), j = min(n, k / 2);
        if (nums1[i - 1] > nums2[j - 1]) {
            return findKth(nums1, vector<int>(nums2.begin() + j, nums2.end()), k - j);
        } else {
            return findKth(vector<int>(nums1.begin() + i, nums1.end()), nums2, k - i);
        }
        return 0;
    }
};