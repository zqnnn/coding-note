#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//用后序遍历，这样我们只需要遍历一次即可，需要需要存储一下左右子树的深度。
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot, &depth);
    }

    bool IsBalanced(TreeNode* pRoot, int* depth){
        if(!pRoot){
            *depth = 0;
            return true;
        }
        int left, right;
        if(IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)){
            int diff = left - right;
            if(diff <= 1 && diff >= -1){
                *depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
};