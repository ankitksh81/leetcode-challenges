/*
	Prefix and Suffix Search
	https://leetcode.com/problems/prefix-and-suffix-search/
*/

// Solution 1: Hashmap

class WordFilter {
    unordered_map<string, int> mp;
public:
    WordFilter(vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        for (int i = 0; i < words.size(); i++) {
            string pref;
            for (int j = 0; j < words[i].length(); j++) {
                pref += words[i][j];
                string suff;
                for (int k = words[i].length() - 1; k >= 0; k--) {
                    suff = words[i][k] + suff;
                    mp[pref + "#" + suff] = i + 1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        return mp[prefix + "#" + suffix] - 1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */


// Solution 2: Trie of Suffix Wrapped Words

struct Trie {
    unordered_map<char, Trie*> children;
    int weight;
    
    Trie() : weight(-1) {}
};

class WordFilter {
    Trie* root = new Trie();
public:
    WordFilter(vector<string>& words) {
        for (int w = 0; w < words.size(); w++) {
            string word = words[w] + "#";
            for (int i = 0; i < word.length(); i++) {
                Trie* cur = root;
                cur->weight = w;
                for (int j = i; j < 2 * word.length() - 1; j++) {
                    char ch = word[j % word.length()];
                    if (cur->children.find(ch) == cur->children.end()) {
                        cur->children[ch] = new Trie();
                    }
                    cur = cur->children[ch];
                    cur->weight = w;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        Trie* cur = root;
        string str = suffix + "#" + prefix;
        for (char c : str) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new Trie();
            }
            cur = cur->children[c];
        }
        
        return cur->weight;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */