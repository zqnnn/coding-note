//
// Created by zqn on 2019/9/2.
//



//二叉搜索树中的第K小的元素
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//中序遍历得到一个有序vector
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        values(root, res);
        return res[k-1];
    }


    void values(TreeNode* root, vector<int> &res){
        if(!root) return;
        if(root->left){
            values(root->left, res);
        }
        res.push_back(root->val);
        if(root->right){
            values(root->right, res);
        }
    }
};


//非递归
int kthSmallest(TreeNode* root, int k){
    if(!root || k == 0) return 0;
    stack<TreeNode*> st;
    int cnt = 0;
    while (!st.empty() || root){
        while (root){
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        cnt++;
        if(cnt == k)
            return root->val;
        root = root->right;
    }
    return 0;
}



int main(){
    Solution s;

}