//
// Created by zqn on 2019/5/27.
//
#include <vector>
using namespace std;


//LeetCode（105）：从前序与中序遍历序列构造二叉树
//Medium！
//
//题目描述：
//
//根据一棵树的前序遍历与中序遍历构造二叉树。
//
//注意:
//你可以假设树中没有重复的元素。
//
//例如，给出
//
//前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7]
//返回如下的二叉树：
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//解题思路：
//
//这道题要求用先序和中序遍历来建立二叉树，由于先序的顺序的第一个肯定是根，所以原二叉树的根节点可以知道，
// 题目中给了一个很关键的条件就是树中没有相同元素，有了这个条件我们就可以在中序遍历中也定位出根节点的位置，
// 并以根节点的位置将中序遍历拆分为左右两个部分，分别对其递归调用原函数。

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, inorder, 0, inorder.size()-1);

    }

    TreeNode* build(vector<int>& preorder, int pIndex, vector<int>& inorder, int iLeft, int iRight){
       if(iLeft > iRight) return NULL;
       int i = 0;
       for(i = iLeft; i <= iRight; i++){
           if(preorder[pIndex] == inorder[i]) break;
       }

       TreeNode *root = new TreeNode(preorder[pIndex]);
       root->left = build(preorder, pIndex+1, inorder, iLeft, i-1);
       root->right = build(preorder, pIndex+i-iLeft+1, inorder, i+1, iRight);
    }
};