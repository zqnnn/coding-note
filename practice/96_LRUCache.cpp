//
// Created by zhangqianni on 2019-08-02.
//

//运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
//
//获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
//写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值留出空间。
//
//进阶:
//
//你是否可以在 O(1) 时间复杂度内完成这两种操作？
//
//示例:
//
//LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );
//
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // 返回  1
//cache.put(3, 3);    // 该操作会使得密钥 2 作废
//cache.get(2);       // 返回 -1 (未找到)
//cache.put(4, 4);    // 该操作会使得密钥 1 作废
//cache.get(1);       // 返回 -1 (未找到)
//cache.get(3);       // 返回  3
//cache.get(4);       // 返回  4


//这道题让我们实现一个 LRU 缓存器，LRU 是 Least Recently Used 的简写，就是最近最少使用的意思。
// 那么这个缓存器主要有两个成员函数，get 和 put，
// 其中 get 函数是通过输入 key 来获得 value，如果成功获得后，这对 (key, value) 升至缓存器中最常用的位置（顶部），
// 如果 key 不存在，则返回 -1。
// 而 put 函数是插入一对新的 (key, value)，如果原缓存器中有该 key，则需要先删除掉原有的，将新的插入到缓存器的顶部。
// 如果不存在，则直接插入到顶部。若加入新的值后缓存器超过了容量，则需要删掉一个最不常用的值，也就是底部的值。
// 具体实现时我们需要三个私有变量，cap, l和m，
// 其中 cap 是缓存器的容量大小，
// l是保存缓存器内容的列表，
// m是 HashMap，保存关键值 key 和缓存器各项的迭代器之间映射，方便我们以 O(1) 的时间内找到目标项。

#include <list>
#include <utility>
#include <unordered_map>
using namespace std;


//list<pair<int,int>> 是一个双向链表，存储键值(key,value)
//map<int,list<pair<int,int>>::iterator>>是用来存放key值所对应的list中的位置

class LRUCache {
private:
    int n;
    list<pair<int, int>> lis;
    unordered_map<int, list<pair<int, int>>::iterator> m;
public:
    LRUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        lis.splice(lis.begin(), lis, it->second);//把it->second迭代器指的元素挪到lis的开始位置
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()) lis.erase(it->second);
        lis.push_front(make_pair(key, value));
        m[key] = lis.begin();
        if(m.size() > n){
            int k = lis.rbegin()->first;
            lis.pop_back();
            m.erase(k);
        }

    }
};
