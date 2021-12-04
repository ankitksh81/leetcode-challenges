/*
    Stream of characters
    https://leetcode.com/problems/stream-of-characters/
*/

// Solution: Trie

class Trie {
    vector<Trie*> children;
    bool isLeaf;
    
public:
    Trie(): isLeaf(false), children(26) {} 
    void insert(string &s) {
        Trie* cur = this;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(!cur->children[s[i] - 'a'])
                cur->children[s[i] - 'a'] = new Trie();
            cur = cur->children[s[i] - 'a'];
        }
        cur->isLeaf = true;
    }
    
    bool search(string &s) {
        Trie* cur = this;
        for(int i = s.length() - 1; i >= 0; i--) {
            if(!cur->children[s[i] - 'a'])
                return false;
            cur = cur->children[s[i] - 'a'];
            if(cur->isLeaf) {
                return true;
            }
        }
        return false;
    }
};

class StreamChecker {
    Trie* trie = new Trie();
    string stream = "";
public:
    StreamChecker(vector<string>& words) {
        for(string &word: words) {
            trie->insert(word);
        }
    }
    
    bool query(char letter) {
        stream += letter;
        return trie->search(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */