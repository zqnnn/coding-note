//
// Created by zqn on 2019/5/31.
//

//给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
//
//每次转换只能改变一个字母。
//转换过程中的中间单词必须是字典中的单词。
//说明:
//
//如果不存在这样的转换序列，返回 0。
//所有单词具有相同的长度。
//所有单词只由小写字母组成。
//字典中不存在重复的单词。
//你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

//示例 1:
//
//输入:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//
//输出: 5
//
//解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//     返回它的长度 5。
//示例 2:
//
//输入:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//输出: 0
//
//解释: endWord "cog" 不在字典中，所以无法进行转换。


#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

//单词之间的转换，可以理解为一张图，图的顶点为单词，若两个单词可以互相转换，
// 则将这两个单词所代表的的顶点之间连上一条边，
// 求图中节点 hit 到节点 cog 的所有路径中，最少包含多少个节点，即图的宽度优先搜索。


//指定图的起点 beginWord 和终点 endWord，图 graph，从 beginWord 开始宽度优先搜索图 graph ，搜索过程中记录达到的步数。
//
//1、设置搜索队列Q，队列节点为pair<顶点，步数>；设置集合visit，记录搜索过的节点，将<beginWord, 1>添加至队列。
//
//2、只要队不空，取出队列头部元素
//
//若队列头部元素为endWord，返回到达当前节点的步数
//若队列头部不是endWord，则继续扩展该节点，将该节点相邻的且尚未添加到visit中的节点与步数同时添加到队列Q中，并将扩展节点加入visit
//3、若最终无法搜索到endWord，则返回0.
//
//（蓝色指队列中的点，红色代表添加过的点）
//---------------------

class Solution {
public:
    //计算两个单词之间不相等的字符个数
    bool connect(const string &word1, const string &word2){
        int cnt = 0;
        for(int i = 0; i < word1.length(); i++){
            if(word1[i] != word2[i]){
                cnt++;
            }
        }
        //如果只有一个字符不相等，返回true
        return cnt == 1;
    }

    void construct_graph(string &beginWord, vector<string> &wordList, map<string, vector<string>> &graph){
        //wordlist里面没有beginWord
        wordList.push_back(beginWord);
        for(int i = 0; i < wordList.size(); i++){
            graph[wordList[i]] = vector<string>();
        }
        for(int i = 0; i < wordList.size(); i++){
            for(int j = i + 1; j < wordList.size(); j++){
                //若i和j只差一个字符，则将它们相连
                if(connect(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }

    int bfs_graph(string &beginWord, string &endWord, map<string, vector<string>> &graph){
        //搜索队列
        queue<pair<string, int>> Q;
        //标记已访问节点
        set<string> visit;
        //添加起始节点，初始化访问步数为1
        Q.push(make_pair(beginWord, 1));
        //将起始节点标记为已访问
        visit.insert(beginWord);

        while (!Q.empty()){
            //获取队列头结点的字符串和步数
            string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            //如果访问到了endWord,结束
            if(node == endWord){
                return step;
            }
            //获取node的全部邻接点
            const vector<string> &neighbors = graph[node];
            for(auto i : neighbors){
                //如果该邻接点没有被访问过
                if(visit.find(i) == visit.end()){
                    Q.push(make_pair(i, step+1));
                    visit.insert(i);
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.empty() || endWord.empty()) return 0;
        map<string, vector<string>> map;
        construct_graph(beginWord, wordList, map);
        return bfs_graph(beginWord, endWord, map);
    }
};


//这道词句阶梯的问题给了我们一个单词字典，里面有一系列很相似的单词，然后给了一个起始单词和一个结束单词，每次变换只能改变一个单词，
// 并且中间过程的单词都必须是单词字典中的单词，让我们求出最短的变化序列的长度。
// 这道题还是挺有难度的，我当然是看了别人的解法才写出来的，这没啥的，从不会到完全掌握才是成长嘛～
//
//当拿到题就懵逼的我们如何才能找到一个科学的探索解题的路径呢，那就是先别去管代码实现，
// 如果让我们肉身解题该怎么做呢？让你将 'hit' 变为 'cog'，那么我们发现这两个单词没有一个相同的字母，
// 所以我们就尝试呗，博主会先将第一个 'h' 换成 'c'，看看 'cit' 在不在字典中，发现不在，
// 那么把第二个 'i' 换成 'o'，看看 'hot' 在不在，发现在，完美！然后尝试 'cot' 或者 'hog'，发现都不在，
// 那么就比较麻烦了，我们没法快速的达到目标单词，需要一些中间状态，但我们怎么知道中间状态是什么。
// 简单粗暴的方法就是brute force，遍历所有的情况，我们将起始单词的每一个字母都用26个字母来替换，
// 比如起始单词 'hit' 就要替换为 'ait', 'bit', 'cit', .... 'yit', 'zit'，将每个替换成的单词都在字典中查找一下，
// 如果有的话，那么说明可能是潜在的路径，要保存下来。那么现在就有个问题，比如我们换到了 'hot' 的时候，
// 此时发现在字典中存在，那么下一步我们是继续试接下来的 'hpt', 'hqt', 'hrt'...
// 还是直接从 'hot' 的首字母开始换 'aot', 'bot', 'cot' ... 这实际上就是BFS和DFS的区别，
// 到底是广度优先，还是深度优先。讲到这里，不知道你有没有觉得这个跟什么很像？
// 对了，跟迷宫遍历很像啊，你想啊，迷宫中每个点有上下左右四个方向可以走，而这里有26个字母，就是二十六个方向可以走，本质上没有啥区别啊！
// 如果熟悉迷宫遍历的童鞋们应该知道，应该用BFS来求最短路径的长度，
// 这也不难理解啊，DFS相当于一条路走到黑啊，你走的那条道不一定是最短的啊。
// 而BFS相当于一个小圈慢慢的一层一层扩大，相当于往湖里扔个石头，一圈一圈扩大的水波纹那种感觉，
// 当水波纹碰到湖上的树叶时，那么此时水圈的半径就是圆心到树叶的最短距离。脑海中有没有浮现出这个生动的场景呢？
//
//明确了要用BFS，我们可以开始解题了，为了提到字典的查找效率，我们使用HashSet保存所有的单词。
// 然后我们需要一个HashMap，来建立某条路径结尾单词和该路径长度之间的映射，并把起始单词映射为1。
// 既然是BFS，我们需要一个队列queue，把起始单词排入队列中，开始队列的循环，取出队首词，然后对其每个位置上的字符，用26个字母进行替换，
// 如果此时和结尾单词相同了，就可以返回取出词在哈希表中的值加一。
// 如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，
// 并在哈希表中的值映射为之前取出词加一。如果循环完成则返回0，参见代码如下：


int ladderLength(string beginWord, string endWord, vector<string> &wordList){
    set<string> wordDict(wordList.begin(), wordList.end());
    if(wordDict.find(endWord) == wordDict.end()) return 0;
    unordered_map<string, int> map;
    map[beginWord] = 1;
    queue<string> q;
    q.push(beginWord);
    while (!q.empty()){
        string word = q.front();
        q.pop();
        for(int i = 0; i < word.length(); i++){
            string newWord = word;
            for(char c = 'a'; c <= 'z'; c++){
                newWord[i] = c;

                //如果此时和结尾单词相同了，就可以返回取出词在哈希表中的值加一。
                if(newWord == endWord && wordDict.count(newWord)) return map[word]+1;

                //如果替换词在字典中存在但在哈希表中不存在，则将替换词排入队列中，并在哈希表中的值映射为之前取出词加一。
                if(!map.count(newWord) && wordDict.count(newWord)){
                    q.push(newWord);
                    map[newWord] = map[word] + 1;
                }
            }
        }
    }
    return 0;
}