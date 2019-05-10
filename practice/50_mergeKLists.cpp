//
// Created by zqn on 2019/5/10.
//


//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例:
//
//输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6
//题目分析：本题首先将每个链表的首元素取出，构建一个最小堆。
// 堆顶则为最小的元素，用最小元素所在的那个链表的第二个元素替换掉它的位置。
// 然后维护最小堆的特性，再取出堆顶元素，……，一直到所有链表元素都取出为止。
//
//时间复杂度分析：一共是K个链表，假设每个链表有n个元素，首先是K个链表首元素的建堆，花费O(K)，然后取堆顶元素，
// 用下一个元素替换掉它，维护最小堆的特性，花费O(lgK)，共有K*n个元素，所以花费(K*n-1)*lgK的时间，故总时间为O(K*n*lgK)
//
//我们用优先队列来实现，优先队列的底层是用堆实现的。
// 所谓优先，指的是队列里的元素按照优先级大小排列，优先级大的排在前面，优先级相同的按照入队的顺序排列。
// 首先将每个链表的首元素入队，将最小元素置于堆顶，然后找最小元素所在链表的下一个元素入队，一直到队为空。

#include <vector>
#include <queue>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    struct cmp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i])
                q.push(lists[i]);
        }
        ListNode *head = new ListNode(0); //哨兵
        ListNode *tmp = head;

        while (!q.empty()){
            tmp->next = q.top();
            tmp = tmp->next;
            q.pop();
            if(tmp->next)
                q.push(tmp->next);
        }
        return head->next;
    }
};
