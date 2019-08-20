//
// Created by zqn on 2019/8/20.
//

//反转链表
//
//　　辅助指针：定义三个用于翻转链表的辅助指针和一个用于表示翻转链表头结点的指针，
// node指向当前节点、left指向当前节点的前一个节点、right指向当前节点的下一个节点、ReverseHead指向翻转链表的头结点。
//
//　　翻转链表过程：循环翻转链表，每次循环翻转一个结点。判断node是否是最后一个结点，如果是最后一个节点，则reverseHead指向node（确定翻转链表表头节点），
// 然后node指向left（翻转链表），退出循环；如果不是最后一个节点，则node指向left（翻转链表），移动left和node指针。
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* left = nullptr;
        ListNode* cur = head;
        ListNode* right = nullptr;
        ListNode* newhead = nullptr;
        while (cur != nullptr){
            right = cur->next;
            if(right == nullptr){
                newhead = cur;
            }

            cur->next = left;
            left = cur;
            cur = right;
        }
        return newhead;

    }
};
