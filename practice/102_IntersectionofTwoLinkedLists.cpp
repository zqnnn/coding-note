//
// Created by zhangqianni on 2019-08-15.
//

//求两个链表的交点

//具体算法为：分别遍历两个链表，得到分别对应的长度。然后求长度的差值，把较长的那个链表向后移动这个差值的个数，然后一一比较即可。代码如下：

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = gerLength(headA);
        int lengthB = gerLength(headB);

        if(lengthA >= lengthB){
            int p = lengthA - lengthB;
            while (p > 0){
                headA = headA->next;
                p--;
            }
        }
        else{
            int p = lengthB - lengthA;
            while (p > 0) {
                headB = headB->next;
                p--;
            }
        }

        while (headA && headB && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        if(!headA || !headB) return nullptr;
        else{
            return headA;
        }

    }


    int gerLength(ListNode* a){
        int cnt = 0;
        while (a){
            a = a->next;
            cnt++;
        }
        return cnt;
    }
};