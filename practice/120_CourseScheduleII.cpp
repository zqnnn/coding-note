//
// Created by zqn on 2019/8/26.
//


//现在你总共有 n 门课需要选，记为 0 到 n-1。
//
//在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
//
//给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
//
//可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
//




//这题是之前那道 Course Schedule 的扩展，那道题只让我们判断是否能完成所有课程，即检测有向图中是否有环，而这道题我们得找出要上的课程的顺序，
// 即有向图的拓扑排序 Topological Sort，这样一来，难度就增加了，但是由于我们有之前那道的基础，
// 而此题正是基于之前解法的基础上稍加修改，我们从 queue 中每取出一个数组就将其存在结果中，最终若有向图中有环，
// 则结果中元素的个数不等于总课程数，那我们将结果清空即可。


#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //定义二维数组 graph 来表示这个有向图，一维数组 in 来表示每个顶点的入度。
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        vector<int> res;

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
            res.push_back(t);
            q.pop();
            for(auto a: graph[t]){
                --in[a];
                if(in[a] == 0) q.push(a);
            }
        }

        if(res.size() != numCourses) res.clear();
        return res;
    }
};