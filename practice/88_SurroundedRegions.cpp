//
// Created by zqn on 2019/6/3.
//
#include <vector>
using namespace std;

//给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
//
//找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
//
//示例:
//
//X X X X
//X O O X
//X X O X
//X O X X
//运行你的函数后，矩阵变为：
//
//X X X X
//X X X X
//X X X X
//X O X X
//解释:
//
//被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，
// 或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。




//这是道关于XXOO的题，有点像围棋，将包住的O都变成X，但不同的是边缘的O不算被包围，跟之前那道 Number of Islands 很类似，
// 都可以用DFS来解。在网上看到大家普遍的做法是扫面矩阵的四条边，如果有O，则用DFS遍历，
// 将所有连着的O都变成另一个字符，比如$，这样剩下的O都是被包围的，
// 然后将这些O变成X，把$变回O就行了。代码如下：
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if((i == 0 || j == 0 || i == board.size()-1 || j == board[0].size()-1) && board[i][j] == 'O'){
                    DFS(board, i, j);
                }
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }

    void DFS(vector<vector<char>>& board, int i, int j){
        if(board[i][j] == 'O')
            board[i][j] = '$';
        if(i > 0 && board[i-1][j] == 'O')
            DFS(board, i-1, j);
        if(j > 0 && board[i][j-1] == 'O')
            DFS(board, i, j-1);
        if(i < board.size()-1 && board[i+1][j] == 'O')
            DFS(board, i+1, j);
        if(j < board[0].size()-1 && board[i][j+1] == 'O')
            DFS(board, i, j+1);
    }
};