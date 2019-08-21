//
// Created by zqn on 2019/8/21.
//

//实现一个字典树
#include <string>
#include <map>
using namespace std;

struct TrieNode{
    int count;
    map<char, TrieNode*> children;
    TrieNode(){
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* iter = root;
        for(int i = 0; i < word.size(); i++){
            if(iter->children.find(word[i]) == iter->children.end()){
                TrieNode* newNode = new TrieNode();
                iter->children[word[i]] = newNode;
            }
            iter = iter->children[word[i]];
        }
        iter->count++;

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* iter = findNode(word);
        if(iter != NULL && iter->count > 0) return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* iter = findNode(prefix);
        if(iter == NULL) return false;
        return true;
    }


    TrieNode* findNode(string word){
        TrieNode* iter = root;
        for(int i = 0; i < word.size(); i++){
            if(iter->children.find(word[i]) == iter->children.end()){
                return NULL;
            }
            iter = iter->children[word[i]];
        }
        return iter;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */