//
// Created by zqn on 2019/5/27.
//

//LeetCode（103）： 二叉树的锯齿形层次遍历
//Medium！
//
//题目描述：
//
//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//例如：
//给定二叉树 [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回锯齿形层次遍历如下：
//
//[
//  [3],
//  [20,9],
//  [15,7]
//]

#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//递归法

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagLevelOrder(root, 0, res);
        return res;
    }

    void zigzagLevelOrder(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        if(res.size() <= level){
            vector<int> v;
            v.push_back(root->val);
            res.push_back(v);
        }
        else{
            if(level % 2 == 0) res[level].push_back(root->val);
            else{
                res[level].insert(res[level].begin(), root->val);
            }
        }
        zigzagLevelOrder(root->left, level+1, res);
        zigzagLevelOrder(root->right, level+1, res);
    }
};


//非递归
//这道二叉树的之字形层序遍历是之前那道[LeetCode] Binary Tree Level Order Traversal 二叉树层序遍历的变形，
// 不同之处在于一行是从左到右遍历，下一行是从右往左遍历，交叉往返的之字形的层序遍历。
// 根据其特点，我们想到栈也有后进先出的特点，
// 这道题我们维护两个栈，相邻两行分别存到两个栈中，进栈的顺序也不相同，
// 一个栈是先进左子结点然后右子节点，另一个栈是先进右子节点然后左子结点，
// 这样出栈的顺序就是我们想要的之字形了。


class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        stack<TreeNode*> leftInStack, rightInStack;
        rightInStack.push(root);
        vector<int> subres;
        while(!rightInStack.empty() || !leftInStack.empty()){
            while (!rightInStack.empty()){
                TreeNode* node = rightInStack.top();
                rightInStack.pop();
                subres.push_back(node->val);
                if(node->left) leftInStack.push(node->left);
                if(node->right) leftInStack.push(node->right);
            }
            if(!subres.empty()) res.push_back(subres);
            subres.clear();
            while (!leftInStack.empty()){
                TreeNode* node = leftInStack.top();
                leftInStack.pop();
                subres.push_back(node->val);
                if(node->right) rightInStack.push(node->right);
                if(node->left)  rightInStack.push(node->left);
            }
            if(!subres.empty()) res.push_back(subres);
            subres.clear();
        }
        return res;


    }


};