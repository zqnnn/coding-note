//
// Created by zqn on 2019/5/5.
//
//LeetCode（19）：删除链表的倒数第N个节点
//Medium！
//
//题目描述：
//
//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//
//示例：
//
//给定一个链表: 1->2->3->4->5, 和 n = 2.
//
//当删除了倒数第二个节点后，链表变为 1->2->3->5.
//说明：
//
//给定的 n 保证是有效的。
//
//进阶：
//
//你能尝试使用一趟扫描实现吗？


#include <stack>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//1. 使用stack
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        stack<ListNode*> s1;
        ListNode* node = head;
        while(node){
            s1.push(node);
            node = node->next;
        }
        for(int i = 0; i < n; i++){
            s1.pop();
        }
        if(s1.empty()){
            return head->next;
        }
        else{
            s1.top()->next = s1.top()->next->next;
            return head;
        }

    }
};




//2.定义两个指针，一个在前，一个在后，同时遍历ListNode，要求是：开始遍历时fast指针要比slow指针快n步，方法是先让fast指针先移动n步，然后fast和slow再同时移动，直到移动到末尾。
ListNode* removeNthFromEnd(ListNode* head, int n){
    if(!head)
        return NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    int i = 0;
    while(i < n){
        fast = fast->next;
        i++;
    }
    if(!fast)
        return head->next;
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;

}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode* result = removeNthFromEnd(head, 1);
    cout << result->val<<endl;
    return 0;
}