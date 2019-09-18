//
// Created by zqn on 2019/9/18.
//

//从1亿个数里面找出前100个最大的

//堆排序
//用100个数建立一个最小堆，剩下来一亿减100个数依次和堆顶元素比较，如果比堆顶元素小，不管它。
//如果比堆顶元素大，那这个元素就把堆顶元素替换掉，然后调整堆，直到所有的元素都和堆顶元素比较完毕。
//假设一共是n个数，找前m个大的。第一次建堆并调整的时间大约为mlog(m)。对于剩下的元素，最坏的情况是每个都调整堆。
//调整堆一次的时间复杂度为log(m)，所以总时间复杂度为(n-m)log(m)+mlog(m)=nlog(m)


//堆排序基本思路：
//
//步骤一：建立大根堆--将n个元素组成的无序序列构建一个大根堆，
//步骤二：交换堆元素--交换堆尾元素和堆首元素，使堆尾元素为最大元素；
//步骤三：重建大根堆--将前n-1个元素组成的无序序列调整为大根堆
//    重复执行步骤二和步骤三，直到整个序列有序。

//一.建立大根堆
//① 无序序列建立完全二叉树
//② 从最后一个非叶子节点开始，从右到左，从下到上调整，将完全二叉树调整为大根堆
//二.交换堆元素（交换堆首和堆尾元素--获得最大元素）
//三.重建大根堆（前n-1个元素）
//重复执行步骤二和步骤三，直到整个序列有序


#include <vector>
#include <iostream>
using namespace std;


//调整为最小堆
void adjust(vector<int> &nums, int m, int i){
    int tmp = nums[i]; //当前节点的值
    for(int k = 2 * i + 1; k < m; k = 2 * k + 1){
        // //获取当前节点的孩子节点的最大值
        if(k + 1 < m && nums[k + 1] < nums[k]) k++;
        //如果孩子节点更大，则把最大的孩子节点的值赋值给父节点
        if(tmp > nums[k]){
            nums[i] = nums[k];
            i = k;
        }
    }
    nums[i] = tmp;
}


//新建堆
//最后一个非叶子节点的下标为（ m/2-1）
void create_heap(vector<int> &nums, int m){
    for(int i = m/2-1; i >= 0; i--){
        adjust(nums, m, i);
    }
}

void print(vector<int> nums, int m){
    //把前m个数建成最小堆
    create_heap(nums, m);
    //把剩下的nums.size()-m个数字依次与最小堆的堆顶元素比较
    //如果比堆顶元素大，那么就替换为堆顶，然后对堆顶进行调整。
    //当所有的元素遍历一遍后，堆中元素就是前m个最大的。
    for(int i = m; i < nums.size(); i++){
        if(nums[i] > nums[0]){
            nums[0] = nums[i];
            adjust(nums, m, 0);
        }
    }
}


int main(){
    int n = 10000;
    int m = 100;
    vector<int> nums(n, 1);
    for(int i = 0; i < n; i++){
        nums[i] = i+1;
    }

    print(nums, m);
}