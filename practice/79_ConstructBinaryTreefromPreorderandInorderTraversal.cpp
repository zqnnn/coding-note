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


//思路
//根据前序历遍和中序历遍确定树。这里的思路是明确的。因为前序历遍，开头第一个元素就是树的根节点。
// 在中序历遍中，确定了对应的根节点的位置，中序历遍中，根节点左边的全部元素构成树的左子树的节点，根节点右边的全部元素构成树的右子树的所有节点。
//具体做法：
//
//在先序前序历遍序列中找到树的根节点。
//在中序历遍后找到树的根节点位置。
//在前序历遍中，左子树的根节点为父节点之后的一个元素。
// 由中序历遍中根节点的位置，可以知道左子树有多少个节点，
// 由此可以在前序历遍中计算得到右子树的根节点的位置。
//递归的调用就可以得到树。


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