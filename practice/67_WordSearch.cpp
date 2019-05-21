//
// Created by zqn on 2019/5/20.
//
//LeetCode（79）： 单词搜索
//Medium！
//
//题目描述：
//
//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
//
//示例:
//
//board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
//
//给定 word = "ABCCED", 返回 true.
//给定 word = "SEE", 返回 true.
//给定 word = "ABCB", 返回 false.
//解题思路：
//
//这道题是典型的深度优先遍历DFS的应用，原二维数组就像是一个迷宫，可以上下左右四个方向行走，
// 我们以二维数组中每一个数都作为起点和给定字符串做匹配，我们还需要一个和原数组等大小的visited数组，是bool型的，用来记录当前位置是否已经被访问过，
// 因为题目要求一个cell只能被访问一次。如果二维数组board的当前字符和目标字符串word对应的字符相等，
// 则对其上下左右四个邻字符分别调用DFS的递归函数，只要有一个返回true，那么就表示可以找到对应的字符串，否则就不能找到。
//我们还可以不用visited数组，直接对board数组进行修改，将其遍历过的位置改为井号，记得递归调用完后需要恢复之前的状态。
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word.empty())
            return false;
        int m = board.size(), n = board[0].size();
        bool found = false;
        int index = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[index]){
                    dfs(board, word, i, j, index, found);
                    if(found){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void dfs(vector<vector<char>>& board, string word, int i, int j, int index, bool& found){
        if(index == word.size() || found) {
            found = true;
            return;
        }
        int m = board.size(), n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index] || board[i][j] == '#' ) //访问过的地方变成井号
            return;
        board[i][j] = '#';
        dfs(board, word, i+1, j, index+1, found);
        dfs(board, word, i-1, j, index+1, found);
        dfs(board, word, i, j+1, index+1, found);
        dfs(board, word, i, j-1, index+1, found);
        board[i][j] = word[index]; //递归调用完后需要恢复之前的状态。

    }

};