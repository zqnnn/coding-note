//
// Created by zqn on 2019/9/2.
//

//删除链表的一个节点



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node && node->next){
            node->val = node->next->val;
            node->next = node->next->next;
        }
    }
};


