//
// Created by zqn on 2019/9/2.
//

#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        while (head){
            a.push_back(head->val);
            head = head->next;
        }

        int i = 0, j = a.size()-1;
        while (i < j){
            if(a[i] != a[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


//这道题的 Follow up 让我们用 O(1) 的空间
//我们可以在找到中点后，将后半段的链表翻转一下，这样我们就可以按照回文的顺序比较了
//找到链表的中点，这个可以用快慢指针来实现，使用方法可以参见之前的两篇 Convert Sorted List to Binary Search Tree 和 Reorder List，
// 使用快慢指针找中点的原理是 fast 和 slow 两个指针，每次快指针走两步，慢指针走一步，等快指针走完时，慢指针的位置就是中点。

bool isLinkP(ListNode* head){
    if(!head || !head->next) return true;
    ListNode* slow = head, *fast = head;

    //找链表的中点
    while (fast->next || fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* last = slow->next, *pre = head;
    while (last->next){
        ListNode* tmp = last->next;
        last->next = tmp->next;
        tmp->next = slow->next;
        slow->next = tmp;
    }

    while (slow->next){
        slow = slow->next;
        if(pre->val != slow->val) return false;
        pre = pre->next;
    }
    return true;
}