//
// Created by zqn on 2019/4/1.
//


//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//如果数组中不存在目标值，返回 [-1, -1]。
//
//示例 1:
//
//输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4]
//示例 2:
//
//输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1]



#include <vector>
#include <iostream>
using namespace std;
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//你的算法时间复杂度必须是 O(log n) 级别。
//
//如果数组中不存在目标值，返回 [-1, -1]。
//
//示例 1:
//
//输入: nums = [
//5,7,7,8,8,10]
//, target = 8
//输出: [3,4]
//示例 2:
//
//输入: nums = [
//5,7,7,8,8,10]
//, target = 6
//输出: [-1,-1]

//这道题让我们在一个有序整数数组中寻找相同目标值的起始和结束位置，而且限定了时间复杂度为O(logn)，
// 这是典型的二分查找法的时间复杂度，所以这道题也需要用此方法，我们的思路是首先对原数组使用二分查找法，
// 找出其中一个目标值的位置，然后向两边搜索找出起始和结束的位置，代码如下：

int search(vector<int>& nums, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) return search(nums, mid + 1, right, target);
    else return search(nums, left, mid - 1, target);
}
vector<int> searchRange(vector<int>& nums, int target) {
    int idx = search(nums, 0, nums.size() - 1, target);
    if (idx == -1) return {-1, -1};
    int left = idx, right = idx;
    while (left > 0 && nums[left - 1] == nums[idx]) --left;
    while (right < nums.size() - 1 && nums[right + 1] == nums[idx]) ++right;
    return {left, right};
}


//按照二分法的思路，我们可以这样子设计：
//
//①首先根据二分法找到vector中的某个target元素，这个元素是一串target元素中的某一个，记这个元素的索引是med。
//
//②接着从vector的头部开始，到med-1这个位置，根据二分法找到某个元素——元素不是target，但是元素的下一个元素是target。
//
//这个元素的下一个元素，也就是一串target元素中的第一个。
//
//③接着从med+1这个位置开始，到vector的尾部结束，根据二分法找到某个元素——元素不是target，但是元素的前一个元素是target。
//
//这个元素的前一个元素，也就是一串target元素中的最后一个。
//
//
//
//总体思路如上，当然其中要有一些边界情况的处理，比如②中找不到这个元素怎么办，vector是[8,8,8,8,8]，target是8，我们根本找不到一个不是8的元素。
//
//还有，不存在target的边界情况，也要特殊处理一下。
vector<int> searchRange(vector<int>& nums, int target){
    int left=0,right=nums.size()-1,med,t1;//t1是临时变量
    while(left<=right)//用二分法找到某个target元素
    {
        med=(left+right)/2;
    if(nums[med]==target)
        break;
    else if(nums[med]>target)
        right=med-1;
    else
        left=med+1;
    }
    if(left>right)return {-1,-1};//如果找不到target元素，返回[-1,1]

    left=0,right=med-1;//更新left为vector的头部索引，right为med-1
    while(left<=right)//用二分法找到我们想要的元素
    {
        med=(left+right)/2;
        if(nums[med]!=target&&nums[med+1]==target)//满足这个退出条件，nums[med]就是我们要的元素
            break;
        if(nums[med]<target)//不满足退出条件，且当前nums[med]小于target，那么更新left，继续循环
            left=med+1;
        else if(nums[med]==target)//不满足退出条件，且nums[med]是target，那么更新right，继续循环
            right=med-1;
    }
    if(left>right)//如果找不到我们想要的元素，left大于right了，那么med才是target元素的起始位置
        t1=med;
    else//如果找得到我们想要的元素，那么med+1才是target元素的起始位置
        t1=med+1;

    left=med+1,right=nums.size()-1;//更新left为med+1，right为vector的尾部索引
    while(left<=right)//用二分法找到我们想要的元素
    {
        med=(left+right)/2;
        if(nums[med]!=target&&nums[med-1]==target)//满足退出条件就退出
            break;
        if(nums[med]>target)//同上
            right=med-1;
        else if(nums[med]==target)//同上
            left=med+1;
    }
    if(left>right)//如果找不到我们想要的元素，那么med才是target元素的结束位置
        return {t1,med};
    else//如果找得到，那么med-1才是target元素的结束位置
        return {t1,med-1};
    }


int main(){
    vector<int> num = {5,7,7,8,8,10};
    vector<int> result = searchRange(num, 7);
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
}