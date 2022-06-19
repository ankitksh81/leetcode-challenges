/*
	Search Suggestions System
	https://leetcode.com/problems/search-suggestions-system/
*/

// Solution: Trie + DFS

struct Trie {
    bool isLeaf;
    map<char, Trie*> children;
    
    Trie() : isLeaf(false) {}
    
    void insert(string &word) {
        Trie* cur = this;
        for (char c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new Trie();
            }
            cur = cur->children[c];
        }
        cur->isLeaf = true;
    }
    
    void getSuggestionsUtil(Trie* cur, string &prefix, vector<string>& res) {
        if (res.size() == 3)    return;
        if (cur->isLeaf)    res.push_back(prefix);
        
        for (auto it : cur->children) {
            prefix += it.first;
            getSuggestionsUtil(it.second, prefix, res);
            prefix.pop_back();
        }
    }
    
    vector<string> getSuggestions(string &prefix) {
        Trie* cur = this;
        vector<string> result;
        
        for (char c : prefix) {
            if (cur->children.find(c) == cur->children.end()) {
                return result;
            }
            cur = cur->children[c];
        }
        
        getSuggestionsUtil(cur, prefix, result);
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int N = products.size();
        vector<vector<string>> result;
        Trie* root = new Trie();
        
        for (string product : products) {
            root->insert(product);
        }
        
        string prefix = "";
        for (char c : searchWord) {
            prefix += c;
            result.push_back(root->getSuggestions(prefix));
        }
        
        return result;
    }
};