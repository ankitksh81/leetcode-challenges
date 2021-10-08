/*
    Implement trie prefix tree
    https://leetcode.com/problems/implement-trie-prefix-tree/submissions/
*/

// Solution:

class Trie {
    bool isLeaf = false;
    map<char, Trie*> child = {};
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* cur = this;
        for(char c: word) {
            if(cur->child.find(c) == cur->child.end()) {
                cur->child[c] = new Trie();
            }
            cur = cur->child[c];
        }
        cur->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* cur = this;
        for(char c: word) {
            if(cur->child.find(c) == cur->child.end()) {
                return false;
            }
            cur = cur->child[c];
        }
        return cur->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* cur = this;
        for(char c: prefix) {
            if(cur->child.find(c) == cur->child.end()) {
                return false;
            }
            cur = cur->child[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */