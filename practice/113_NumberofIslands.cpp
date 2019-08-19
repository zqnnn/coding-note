//
// Created by zqn on 2019/8/19.
//

//岛屿的数量
//Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.
//
//Example 1:
//
//Input:
//11110
//11010
//11000
//00000
//
//Output: 1
//Example 2:
//
//Input:
//11000
//11000
//00100
//00011
//
//Output: 3


#include <vector>
#include <iostream>
#include <queue>
using namespace std;

//
//
//这道求岛屿数量的题的本质是求矩阵中连续区域的个数，很容易想到需要用深度优先搜索 DFS 来解，
// 我们需要建立一个 visited 数组用来记录某个位置是否被访问过，对于一个为 ‘1’ 且未被访问过的位置，我们递归进入其上下左右位置上为 ‘1’ 的数，将其 visited 对应值赋为 true，
// 继续进入其所有相连的邻位置，这样可以将这个连通区域所有的数找出来，并将其对应的 visited 中的值赋 true，找完相邻区域后，我们将结果 res 自增1，
// 然后我们在继续找下一个为 ‘1’ 且未被访问过的位置，以此类推直至遍历完整个原数组即可得到最终结果，代码如下：

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        if(grid.empty() || grid[0].empty()) return res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0' || visited[i][j]) continue;
                dfs(grid, i, j, visited);
                res++;
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] == true || grid[i][j] == '0')
            return;
        visited[i][j] = true;
        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j-1, visited);
        dfs(grid, i, j+1, visited);

    }
};




//BFS方法
//在遍历到 ‘1’ 的时候，且该位置没有被访问过，那么就调用一个 BFS 即可，借助队列 queue 来实现，现将当前位置加入队列，
// 然后进行 while 循环，将队首元素提取出来，并遍历其周围四个位置，
// 若没有越界的话，就将 visited 中该邻居位置标记为 true，并将其加入队列中等待下次遍历即可，参见代码如下：
class Solution2{
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        queue<pair<int, int>> q;
        vector<pair<int, int>> v = {{0, -1}, {0, 1}, {1,0}, {-1, 0}};
        q.push({i, j});
        visited[i][j] = 1;
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto iter: v){
                int f = x + iter.first;
                int s = y + iter.second;
                if(f < 0 || s < 0 || f > grid.size()-1 || s > grid[0].size()-1 || grid[f][s] == '0' || visited[f][s] == 1) continue;
                visited[f][s] = 1;
                q.push({f,s});
            }

        }
    }

    int numIslands(vector<vector<char>>& grid){
        int res = 0;
        if(grid.empty() || grid[0].empty()) return res;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0' | visited[i][j] == 1) continue;
                bfs(grid, visited, i, j);
                res++;
            }
        }
        return res;
    }


};



int main(){
    vector<vector<char>> is = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    Solution s;
    cout << s.numIslands(is);
}