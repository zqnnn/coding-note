//
// Created by zqn on 2019/5/14.
//
#include <vector>
#include <iostream>
using namespace std;
//题目描述：
//
//判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
//
//数字 1-9 在每一行只能出现一次。
//数字 1-9 在每一列只能出现一次。
//数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//
//
//上图是一个部分填充的有效的数独。
//
//数独部分空格内已填入了数字，空白格用 '.' 表示。
//
//示例 1:
//
//输入:
//[
//  ["5","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: true
//示例 2:
//
//输入:
//[
//  ["8","3",".",".","7",".",".",".","."],
//  ["6",".",".","1","9","5",".",".","."],
//  [".","9","8",".",".",".",".","6","."],
//  ["8",".",".",".","6",".",".",".","3"],
//  ["4",".",".","8",".","3",".",".","1"],
//  ["7",".",".",".","2",".",".",".","6"],
//  [".","6",".",".",".",".","2","8","."],
//  [".",".",".","4","1","9",".",".","5"],
//  [".",".",".",".","8",".",".","7","9"]
//]
//输出: false
//解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
//     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
//说明:
//
//一个有效的数独（部分已被填充）不一定是可解的。
//只需要根据以上规则，验证已经填入的数字是否有效即可。
//给定数独序列只包含数字 1-9 和字符 '.' 。
//给定数独永远是 9x9 形式的。

//解题思路：
//
//这道题让我们验证一个方阵是否为数独矩阵。
// 判断标准是看各行各列是否有重复数字，以及每个小的3x3的小方阵里面是否有重复数字，
// 如果都无重复，则当前矩阵是数独矩阵，但不代表该数独矩阵有解，只是单纯的判断当前未填完的矩阵是否是数独矩阵。
//
//根据数独矩阵的定义，在遍历每个数字的时候，就看看包含当前位置的行和列以及3x3小方阵中是否已经出现该数字，
// 那么我们需要三个标志矩阵，分别记录各行，各列，各小方阵是否出现某个数字，
// 其中行和列标志下标很好对应，就是小方阵的下标需要稍稍转换一下。

//没看懂
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > rowFlag(m, vector<bool>(n, false));
        vector<vector<bool> > colFlag(m, vector<bool>(n, false));
        vector<vector<bool> > cellFlag(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    int c = board[i][j] - '1';
                    if(rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i /3) + j / 3][c])
                        return false;
                    rowFlag[i][c] = true;
                    colFlag[c][i] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};


//思路：
//
//1、将问题分解，就像我们人判断一样，要判断每一行是否有效，每一列是否有效，还判断每一个九宫格是否满足。
//
//所以将问题划分成三个类型的判断，分别用三个子程序来判断。主程序只负责确定 要判断哪一行，哪一列，哪个格子。
//
//判断格子的时候，以左上角为基准点。
//
//2、通过一个vector来判断是否有效。
// 如果是空，那么就不管，如果不是空，那么存入vector,
// 当下一个非空元素来时，和vector中所有元素比较，如果相等，那么说明无效，否则有效。
//
//3、虽然题目中给的是双引号表示的，当时毕竟是char类型。
// 个人认为，最终程序中还是用的单引号，题目中给出的应该只是表达这道题的一个写法。
// 我自己又在程序中试了试，和当初刚学C的时候一样，char就是要用单引号，用双引号各种错误。

class Solution1{
public:
    bool isValidSudoku(vector<vector<char>> & board){
        int len = 9;
        for(int i = 0; i < len; i++){
            if(isRowValid(i, board) == false)
                return false;
        }
        for(int j = 0; j < len; j++){
            if(isColValid(j, board) == false)
                return false;
        }

        for(int i = 0; i < len; i += 3){
            for(int j = 0 ; j < len; j += 3){
                if(isCellValid(i, j, board) == false)
                    return false;
            }
        }

        return true;
    }

    bool isRowValid(int row, vector<vector<char>> & board){//判断单独一行是否有效
        vector<char> temp;
        for(int i = 0; i < board[0].size(); i++){
            if(board[row][i] == '.')
                continue;
            else{
                temp.push_back(board[row][i]);
            }
            for(int j = 0; j < temp.size()-1; j++){//判断最后push进的元素是否与前面的相同,因为是先push,后比较，所以要小于size（）-1
                if(temp[j] == board[row][i])
                    return false;
            }
        }
        return true;
    }

    bool isColValid(int col, vector<vector<char>> & board){
        vector<char> temp;
        for(int i = 0; i < board.size(); i++){
            if(board[i][col] == '.')
                continue;
            else{
                temp.push_back(board[i][col]);
            }
            for(int j = 0; j < temp.size()-1; j++){//判断最后push进的元素是否与前面的相同,因为是先push,后比较，所以要小于size（）-1
                if(temp[j] == board[i][col])
                    return false;
            }
        }
        return true;
    }

    bool isCellValid(int row, int col, vector<vector<char>> & board){
        vector<char> temp;
        for(int i = row; i < row+3; i++){
            for(int j = col; j < col+3; j++){
                if(board[i][j] == '.')
                    continue;
                else
                    temp.push_back(board[i][j]);

                for(int k = 0; k < temp.size()-1; k++){
                    if(temp[k] == board[i][j])
                        return false;
                }
            }
        }
        return true;
    }
};
