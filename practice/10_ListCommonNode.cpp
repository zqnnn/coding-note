//
// Created by zqn on 2019/3/18.
//

//输入两个链表，找出它们的第一个公共结点。
#include <stack>
#include <list>
using namespace std;


struct ListNode {
    int m_key;
    ListNode *next;
};

//借助外部空间法
//首先，经过分析我们发现两个有公共结点而部分重合的链表，拓扑形状看起来像一个Y，而不可能像X，如下图所示，两个链表在值为6的结点处交汇：
//
//
//
// 如果两个链表有公共结点，那么公共结点出现在两个链表的尾部。如果我们从两个链表的尾部开始往前比较，最后一个相同的结点就是我们要找的结点。
// But，在单链表中只能从头结点开始按顺序遍历，最后才能到达尾结点。最后到达的尾结点却要最先被比较，这是“后进先出”的特性。
// 于是，我们可以使用栈的特点来解决这个问题：分别把两个链表的结点放入两个栈里，这样两个链表的尾结点就位于两个栈的栈顶，接下来比较两个栈顶的结点是否相同。
// 如果相同，则把栈顶弹出接着比较下一个栈顶，直到找到最后一个相同的结点。
//ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
//        if(pHead1 == nullptr || pHead2 == nullptr)
//            return nullptr;
//        stack<ListNode*> s1, s2;
//        while(!pHead1){
//            s1.push(pHead1);
//            pHead1 = pHead1 -> next;
//        }
//        while(!pHead2){
//            s2.push(pHead2);
//            pHead2 = pHead2 -> next;
//        }
//
//        ListNode* p = NULL;
//        if(s1.top() == s2.top()){
//            p = s1.top();
//            s1.pop();
//            s2.pop();
//        }
//        return p;
//}

/*
找出2个链表的长度，然后让长的先走两个链表的长度差，然后再一起走
（因为2个链表用公共的尾部）
*/

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        int len1 = findListLenth(pHead1);
        int len2 = findListLenth(pHead2);
        if(len1 > len2){
            pHead1 = walkStep(pHead1,len1 - len2);
        }else{
            pHead2 = walkStep(pHead2,len2 - len1);
        }
        while(pHead1 != NULL){
            if(pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
    }

    int findListLenth(ListNode *pHead1){
        if(pHead1 == NULL) return 0;
        int sum = 1;
        while(pHead1 = pHead1->next) sum++;
        return sum;
    }

    ListNode* walkStep(ListNode *pHead1, int step){
        while(step--){
            pHead1 = pHead1->next;
        }
        return pHead1;
    }
};


