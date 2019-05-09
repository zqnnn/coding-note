//
// Created by zqn on 2019/5/9.
//
//LeetCode（21）：合并两个有序链表
//Easy！
//
//题目描述：
//
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//递归写法
//下面我们来看递归的写法，当某个链表为空了，就返回另一个。然后核心还是比较当前两个节点值大小，如果l1的小，
// 那么对于l1的下一个节点和l2调用递归函数，将返回值赋值给l1.next，然后返回l1；
// 否则就对于l2的下一个节点和l1调用递归函数，将返回值赋值给l2.next，然后返回l2，参见代码如下：

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *l = l1->val > l2->val ? l2 : l1;
        ListNode *node = l1->val > l2->val ? l1 : l2;
        l->next = mergeTwoLists(l->next, node);
        return l;
    }
};

//非递归
////解题思路：
////
////具体思想就是新建一个链表，然后比较两个链表中的元素值，
//// 把较小的那个链到新链表中，由于两个输入链表的长度可能不同，
//// 所以最终会有一个链表先完成插入所有元素，则直接将另一个未完成的链表直接链入新链表的末尾。代码如下：
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* n = new ListNode(-1);
        ListNode* l = n;
        while (l1 && l2){
            if(l1->val > l2->val){
                l->next = l2;
                l2 = l2->next;
            }
            else{
                l->next = l1;
                l1 = l1->next;
            }
            l = l->next;
        }
        l->next = l1 ? l1 : l2;
        return n->next;
    }
};


