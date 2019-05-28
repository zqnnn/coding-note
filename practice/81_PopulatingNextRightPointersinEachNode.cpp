//
// Created by zqn on 2019/5/28.
//


#include <queue>
using namespace std;
//LeetCode（116）：填充同一层的兄弟节点
//Medium！
//
//题目描述：
//
//给定一个二叉树
//
//struct TreeLinkNode {
//  TreeLinkNode *left;
//  TreeLinkNode *right;
//  TreeLinkNode *next;
//}
//填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
//
//初始状态下，所有 next 指针都被设置为 NULL。
//
//说明:
//
//你只能使用额外常数空间。
//使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
//你可以假设它是一个完美二叉树（即所有叶子节点都在同一层，每个父节点都有两个子节点）。
//示例:
//
//给定完美二叉树，
//
//     1
//   /  \
//  2    3
// / \  / \
//4  5  6  7
//调用你的函数后，该完美二叉树变为：
//
//     1 -> NULL
//   /  \
//  2 -> 3 -> NULL
// / \  / \
//4->5->6->7 -> NULL

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

//由于是完全二叉树，所以若节点的左子结点存在的话，其右子节点必定存在，
// 所以左子结点的next指针可以直接指向其右子节点，
//
// 对于其右子节点的处理方法是，判断其父节点的next是否为空，
// 若不为空，则指向其next指针指向的节点的左子结点，若为空则指向NULL。

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        Node* node = root;
        if(node->left){
            node->left->next = node->right;
        }
        if(node->right){
           if(node->next != nullptr){
               node->right->next = node->next->left;
           }
           else{
               node->right->next = nullptr;
           }
        }
        node->left = connect(node->left);
        node->right = connect(node->right);
        return root;

    }
};



//非递归
//对于非递归的解法要稍微复杂一点，但也不算特别复杂，需要用到queue来辅助，
// 由于是层序遍历，每层的节点都按顺序加入queue中，
// 而每当从queue中取出一个元素时，将其next指针指向queue中下一个节点即可。

class Solution2 {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                if(i < size-1){ //每一层的最后一个结点的next结点为空
                    node->next = q.front();
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};
