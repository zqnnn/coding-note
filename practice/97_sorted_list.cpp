//
// Created by zhangqianni on 2019-08-05.
//

//常见排序方法有很多，插入排序，选择排序，堆排序，快速排序，冒泡排序，归并排序，桶排序等等。。
// 它们的时间复杂度不尽相同，而这里题目限定了时间必须为O(nlgn)，符合要求只有快速排序，归并排序，堆排序，而根据单链表的特点，最适于用归并排序。
// 为啥呢？这是由于链表自身的特点决定的，由于不能通过坐标来直接访问元素，所以快排什么的可能不太容易实现（但是被评论区的大神们打脸，还是可以实现的），
// 堆排序的话，如果让新建结点的话，还是可以考虑的，若只能交换结点，最好还是不要用。
// 而归并排序（又称混合排序）因其可以利用递归来交换数字，天然适合链表这种结构。

//归并排序的核心是一个 merge() 函数，其主要是合并两个有序链表，这个在 LeetCode 中也有单独的题目 Merge Two Sorted Lists。
//由于两个链表是要有序的才能比较容易 merge，那么对于一个无序的链表，如何才能拆分成有序的两个链表呢？
//我们从简单来想，什么时候两个链表一定都是有序的？就是当两个链表各只有一个结点的时候，一定是有序的。
//而归并排序的核心其实是分治法 Divide and Conquer，就是将链表从中间断开，分成两部分，
//左右两边再分别调用排序的递归函数 sortList()，
//得到各自有序的链表后，再进行 merge()，这样整体就是有序的了。
//因为子链表的递归函数中还是会再次拆成两半，当拆到链表只有一个结点时，无法继续拆分了，
// 而这正好满足了前面所说的“一个结点的时候一定是有序的”，这样就可以进行 merge 了。
//然后再回溯回去，每次得到的都是有序的链表，然后进行 merge，直到还原整个长度。

//这里将链表从中间断开的方法，采用的就是快慢指针，大家可能对快慢指针找链表中的环比较熟悉，
// 其实找链表中的中点同样好使，因为快指针每次走两步，慢指针每次走一步，当快指针到达链表末尾时，慢指针正好走到中间位置
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head, *fast = head, *pre = head;
        while (fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; //断开操作
        return merge(sortList(head), sortList(slow));

    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* res = new ListNode(-1);
        ListNode* temp = res;
        while (l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        return res->next;
    }
};