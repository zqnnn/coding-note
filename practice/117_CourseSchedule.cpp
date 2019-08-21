//
// Created by zqn on 2019/8/21.
//

//现在你总共有 n 门课需要选，记为 0 到 n-1。
//
//在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
//
//给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
//
//示例 1:
//
//输入: 2, [[1,0]]
//输出: true
//解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
//示例 2:
//
//输入: 2, [[1,0],[0,1]]
//输出: false
//解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
//说明:
//
//输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
//你可以假定输入的先决条件中没有重复的边。
//提示:
//
//这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
//通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
//拓扑排序也可以通过 BFS 完成。



//这道课程清单的问题对于我们学生来说应该不陌生，因为我们在选课的时候经常会遇到想选某一门课程，发现选它之前必须先上了哪些课程，
// 这道题给了很多提示，第一条就告诉我们了这道题的本质就是    在有向图中检测环。
// LeetCode 中关于图的题很少，有向图的仅此一道，还有一道关于无向图的题是 Clone Graph。
// 个人认为图这种数据结构相比于树啊，链表啊什么的要更为复杂一些，尤其是有向图，很麻烦。
// 第二条提示是在讲如何来表示一个有向图，可以用边来表示，边是由两个端点组成的，用两个点来表示边。
// 第三第四条提示揭示了此题有两种解法，DFS 和 BFS 都可以解此题。
//
// 我们先来看 BFS 的解法，我们定义二维数组 graph 来表示这个有向图，一维数组 in 来表示每个顶点的入度。
// 我们开始先根据输入来建立这个有向图，并将入度数组也初始化好。
// 然后我们定义一个 queue 变量，将所有入度为0的点放入队列中，然后开始遍历队列，
// 从 graph 里遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度为0，则放入队列末尾。
// 直到遍历完队列中所有的值，若此时还有节点的入度不为0，则说明环存在，返回 false，反之则返回 true。代码如下：

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses);

        for(auto a: prerequisites){
            graph[a[1]].push_back(a[0]);
            ++in[a[0]];
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(in[i] == 0) q.push(i);
        }

        while (!q.empty()){
            int t = q.front();
            q.pop();
            for(auto i: graph[t]){
                --in[i];
                if(in[i] == 0) q.push(i);
            }
        }


        for(int i = 0; i < numCourses; i++){
            if(in[i] != 0) return false;
        }

        return true;
    }
};


//下面我们来看 DFS 的解法，也需要建立有向图，还是用二维数组来建立，和 BFS 不同的是，
// 我们像现在需要一个一维数组 visit 来记录访问状态，这里有三种状态，0表示还未访问过，1表示已经访问了，-1 表示有冲突。
// 大体思路是，先建立好有向图，然后从第一个门课开始，找其可构成哪门课，暂时将当前课程标记为已访问，然后对新得到的课程调用 DFS 递归，直到出现新的课程已经访问过了，则返回 false，
// 没有冲突的话返回 true，然后把标记为已访问的课程改为未访问。代码如下：
//
//

class Solution2{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visited(numCourses);

        for(auto a: prerequisites){
            graph[a[1]].push_back(a[0]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!canFinishDFS(graph, visited, i)) return false;
        }
        return true;
    }


    bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visited, int i){
        if(visited[i] == -1) return false;
        if(visited[i] == 1) return true;
        visited[i] = -1;
        for(auto x: graph[i]){
            if(!canFinishDFS(graph, visited, x)) return false;
        }
        visited[i] = 1;
        return true;
    }
};