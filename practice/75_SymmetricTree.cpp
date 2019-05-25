//
// Created by zqn on 2019/5/25.
//

//LeetCode（101）：对称二叉树
//Easy！
//
//题目描述：
//
//给定一个二叉树，检查它是否是镜像对称的。
//
//例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
//
//    1
//   / \
//  2   2
//   \   \
//   3    3
//说明:
//
//如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
//
//解题思路：
//
//判断二叉树是否是平衡树，比如有两个节点n1, n2，我们需要比较n1的左子节点的值和n2的右子节点的值是否相等，
// 同时还要比较n1的右子节点的值和n2的左子结点的值是否相等，
// 以此类推比较完所有的左右两个节点。我们可以用递归和迭代两种方法来实现，写法不同，但是算法核心都一样。

#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root->left, root->right);

    }

    bool isSymmetric(TreeNode* node1, TreeNode* node2){
        if(!node1 && !node2) return true;
        if((node1 && !node2) || (!node1 && node2) || (node1->val != node2->val)) return false;
        return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
    }
};


//迭代方法 (Iterative Solution)：
//建立两个队列，一个存左子树的节点，按照（左孩子，右孩子）的顺序
//一个存右子树的节点，按照（右孩子，左孩子）的顺序
//按顺序比较两个队列的头节点值
class Solution2{
public:
    bool isS(TreeNode* root){
        if(!root) return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);

        while (!q1.empty() && !q2.empty()){
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();
            q2.pop();
            if((!node1 && node2) || (node1 && !node2)) return false;
            if(node1){
                if(node1->val != node2->val) return false;
                q1.push(node1->left);
                q1.push(node1->right);
                q2.push(node2->right);
                q2.push(node2->left);
            }
        }

        return true;
    }
};