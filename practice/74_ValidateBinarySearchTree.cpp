//
// Created by zqn on 2019/5/24.
//
#include <vector>
#include <limits.h>
using namespace std;


//LeetCode（98）： 验证二叉搜索树
//Medium！
//
//题目描述：
//
//给定一个二叉树，判断其是否是一个有效的二叉搜索树。
//
//一个二叉搜索树具有如下特征：
//
//节点的左子树只包含小于当前节点的数。
//节点的右子树只包含大于当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。
//示例 1:
//
//输入:
//    2
//   / \
//  1   3
//输出: true
//示例 2:
//
//输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。
//解题思路：
//
//这道验证二叉搜索树有很多种解法，可以利用它本身的性质来做，即左<根<右，也可以通过利用中序遍历结果为有序数列来做，
//
// 下面我们先来看最简单的一种，就是利用其本身性质来做，初始化时带入系统最大值和最小值，
// 在递归过程中换成它们自己的节点值，用long代替int就是为了包括int的边界条件，代码如下：
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode* root, long mn, long mx){
        if(!root) return true;
        if(root->val <= mn || root->val >=mx) return false;
        return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
    }
};


class Solution2{
public:
    void Inorder(TreeNode* root, vector<int> &res){
        if(!root) return;
        if(root->left) Inorder(root->left, res);
        res.push_back(root->val);
        if(root->right) Inorder(root->right, res);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> res;
        Inorder(root, res);
        for(int i = 0; i < res.size()-1; i++){
            if(res[i] >= res[i+1])
                return false;
        }
        return true;
    }
};