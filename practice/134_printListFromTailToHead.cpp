//
// Created by zqn on 2019/9/16.
//


//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
       int val;
       struct ListNode *next;
       ListNode(int x) :
             val(x), next(NULL) {
       }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        if(head != NULL){
            v.insert(v.begin(), head->val);
            while (head->next){
                head = head->next;
                v.insert(v.begin(), head->val);
            }
        }
        return v;
    }
};

int main(){

}