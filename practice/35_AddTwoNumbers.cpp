//
// Created by zqn on 2019/4/20.
//


//题目描述：
//
//给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
//
//你可以假设除了数字 0 之外，这两个数字都不会以零开头。
//
//示例：
//
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807
//思路：
//
//本题的思路很简单，按照小学数学中学习的加法原理从末尾到首位，对每一位对齐相加即可。技巧在于如何处理不同长度的数字，
// 以及进位和最高位的判断。将两个单链表表示的数字相加，再将结果用单链表表示出来。主要考察对链表的操作，
// 对链表这种数据结构的遍历、增、删等操作应该熟练。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *l = &preHead;
        int b = 0;
        while (l1 || l2 || b){
            int l1v = l1 ? l1->val : 0;
            int l2v = l2 ? l2->val : 0;
            int a = l1v + l2v + b;
            b = a / 10;
            l->next = new ListNode(a % 10);
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            l = l->next;

        }
        return preHead.next;
    }
};



//知识回顾

#include <iostream>
using namespace std;
/* 创建一个单链表 */
struct ListNode1{
    int m_key;
    ListNode1* next;
};
void createList(ListNode1* pHead){
    ListNode1* p = pHead;
    for (int i = 1; i < 10; ++i) {
        ListNode1* pNewNode = new ListNode1;
        pNewNode->m_key = i; // 将新节点的值赋值为i
        pNewNode->next = NULL;
        p->next = pNewNode; // 上一个节点指向这个新建立的节点
        p = pNewNode; // p节点指向这个新的节点
    }
}
int main(){
    ListNode1* head = NULL;
    head = new ListNode1;
    head->m_key = 0;
    head->next = NULL;
    createList(head);

    return 0;
}