//
// Created by zqn on 2019/8/26.
//

#include <vector>
#include <string>
#include <map>
using namespace std;


//给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
//
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
//


//这道题是在之前那道 Word Search 的基础上做了些拓展，之前是给一个单词让判断是否存在，现在是给了一堆单词，让返回所有存在的单词，
// 在这道题最开始更新的几个小时内，用 brute force 是可以通过 OJ 的，就是在之前那题的基础上多加一个 for 循环而已，
// 但是后来出题者其实是想考察字典树的应用，所以加了一个超大的 test case，以至于 brute force 无法通过，强制我们必须要用字典树来求解。
// LeetCode 中有关字典树的题还有 Implement Trie (Prefix Tree) 和 Add and Search Word - Data structure design，
// 那么我们在这题中只要实现字典树中的 insert 功能就行了，查找单词和前缀就没有必要了，
// 然后 DFS 的思路跟之前那道 Word Search 基本相同，请参见代码如下：


class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) a = NULL;
        }
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i];
            }
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        Trie T;
        for (auto &a : words) T.insert(a);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (T.root->child[board[i][j] - 'a']) {
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }
    void search(vector<vector<char>>& board, TrieNode* p, int i, int j, vector<vector<bool>>& visit, vector<string>& res) {
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        int d[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        visit[i][j] = true;
        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] && p->child[board[nx][ny] - 'a']) {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        visit[i][j] = false;
    }
};