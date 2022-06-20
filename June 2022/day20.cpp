/*
	Short Encoding of Words
	https://leetcode.com/problems/short-encoding-of-words/
*/

// Solution 1: Hashset + storing Prefixes

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        for (string s : words) {
            for (int i = 1; i < s.length(); i++) {
                st.erase(s.substr(i));
            }
        }
        
        int ans = 0;
        for (string w : st) {
            ans += w.length() + 1;
        }
        
        return ans;
    }
};

// Solution 2: Trie

struct Trie {
    bool isLeaf;
    unordered_map<char, Trie*> children;
    
    Trie(): isLeaf(true) {}
    
    int insert(const string &word) {
        Trie* root = this;
        bool isNewBranch = false;
        
        for (char c : word) {
            if (root->children.find(c) == root->children.end()) {
                isNewBranch = true;
                root->children[c] = new Trie();
            }   
            root = root->children[c];
        }
        root->isLeaf = true;
        return isNewBranch ? word.length() : 0;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto &a, auto &b) {
            return a.length() > b.length();
        });
        Trie* root = new Trie();
        int res = 0;
        
        for (auto &word : words) {
            reverse(word.begin(), word.end());
            int cnt = root->insert(word);
            if (cnt) {
                res += cnt + 1;
            }
        }
        
        return res;
    }
};