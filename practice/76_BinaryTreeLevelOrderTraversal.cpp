//
// Created by zqn on 2019/5/25.
//

#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//LeetCode（102）：二叉树的层次遍历
//Medium！
//
//题目描述：
//
//给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
//
//例如:
//给定二叉树: [3,9,20,null,null,15,7],
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回其层次遍历结果：
//
//[
//  [3],
//  [9,20],
//  [15,7]
//]
//解题思路：
//
//层序遍历二叉树是典型的广度优先搜索BFS的应用，但是这里稍微复杂一点的是，我们要把各个层的数分开，存到一个二维向量里面。
//
//大体思路还是基本相同的，建立一个queue，然后先把根节点放进去，这时候找根节点的左右两个子节点，
// 这时候去掉根节点，此时queue里的元素就是下一层的所有节点，
// 用一个for循环遍历它们，然后存到一个一维向量里，遍历完之后再把这个一维向量存到二维向量里，以此类推，可以完成层序遍历。

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            vector<int> sub_res;
            int size = q.size(); //q的size随时在变，要单独拿出来写
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                sub_res.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(sub_res);
        }
        return res;
    }
};

//下面我们来看递归的写法，核心就在于我们需要一个二维数组，和一个变量level，
// 当level递归到上一层的个数时，我们新建一个空层，继续往里面加数字。


class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder2(root, 0, res);
        return res;
    }

    void levelOrder2(TreeNode* root, int level, vector<vector<int>> &res){
        if(!root) return;
        if(res.size() == level) res.push_back({}); //?
        res[level].push_back(root->val);
        if(root->left) levelOrder2(root->left, level+1, res);
        if(root->right) levelOrder2(root->right, level+1, res);
    }
};