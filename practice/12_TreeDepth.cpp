//
// Created by zqn on 2019/3/19.
//

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//递归写法
//class Solution {
//public:
//    int TreeDepth(TreeNode* pRoot)
//    {
//        if(!pRoot)
//            return 0;
//        return max(1+TreeDepth(pRoot->left), 1+TreeDepth(pRoot->right));
//    }
//};


//利用队列进行非递归算法
class Solution{
public:
    int TreeDepth(TreeNode* pRoot){
        if(!pRoot)
            return 0;
        queue<TreeNode*> Q;
        Q.push(pRoot);
        int depth = 0;
        while(!Q.empty()){
            int size = Q.size();
            depth++;
            ////每次只有把在同一层的所有结点出队以后才level++，因此要知道当前队列的长度，用len表示
            for(int i = 0; i < size; i++){
                TreeNode* node = Q.front();
                Q.pop();
                if(pRoot->left) Q.push(pRoot->left);
                if(pRoot->right) Q.push(pRoot->right);
            }
        }
        return depth;
    }
};