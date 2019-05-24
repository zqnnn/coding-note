//
// Created by zqn on 2019/5/24.
//

//LeetCode（94）：二叉树的中序遍历
//Medium！
//
//题目描述：
//
//给定一个二叉树，返回它的中序 遍历。
//
//示例:
//
//输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2]
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//解题思路：
//
//二叉树的中序遍历顺序为左-根-右，可以有递归和非递归来解，其中非递归解法又分为两种，一种是使用栈来解，另一种不需要使用栈。
// 我们先来看递归方法，十分直接，对左子结点调用递归函数，根节点访问值，右子节点再调用递归函数。

#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//递归
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Inorder(root, res);
        return res;
    }

    void Inorder(TreeNode* root, vector<int> &res){
        if(!root) return;
        if(root->left) Inorder(root->left, res);
        res.push_back(root->val);
        if(root->right) Inorder(root->right, res);
    }

};

//下面我们再来看非递归使用栈的解法，也是符合本题要求使用的解法之一，需要用栈来做，思路是从根节点开始，
// 先将根节点压入栈，然后再将其所有左子结点压入栈，然后取出栈顶节点，保存节点值，
// 再将当前指针移到其右子节点上，
// 若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中。
// 这样就保证了访问顺序为左-根-右。

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode *node = root;
        if(root == NULL) return {};

        while (true){
            while (node){
                s.push(node);
                node = node->left;
            }
            if(s.empty()) break;
            node = s.top();
            res.push_back(node->val);
            s.pop();
            node = node->right;
        }
        return res;
    }
};