/*
	Word Abbreviation
	https://leetcode.com/problems/word-abbreviation/
*/

// Solution 1: Greedy

class Solution {
public:
    string getAbbreviation(string word, int i) {
        int N = word.length();
        if (N - i <= 3) return word;
        return word.substr(0, i + 1) + to_string(N - i - 2) + word[N-1];
    }
    
    vector<string> wordsAbbreviation(vector<string>& words) {
        int N = words.size();
        vector<string> result(N);
        vector<int> prefix(N);
        
        for (int i = 0; i < N; i++) {
            result[i] = getAbbreviation(words[i], 0);
        }
        
        for (int i = 0; i < N; i++) {
            while (true) {
                unordered_set<int> duplicates;
                for (int j = i + 1; j < N; j++) {
                    if (result[i] == result[j]) {
                        duplicates.insert(j);
                    }
                }
                if (duplicates.empty()) break;
                duplicates.insert(i);
                
                for (int k : duplicates) {
                    result[k] = getAbbreviation(words[k], ++prefix[k]);
                }
            }
        }
        
        return result;
    }
};

// Solution 2: Trie + Grouping

struct Trie {
    unordered_map<char, Trie*> children;
    int count;
    
    Trie() : count(0) {}
};

struct IndexedWord {
    string word;
    int index;
    
    IndexedWord(string w, int i) {
        word = w;
        index = i;
    }
};

class Solution {
public:
    string getAbbreviation(string s, int i) {
        int N = s.length();
        if (N - i <= 3) return s;
        return s.substr(0, i+1) + to_string(N - i - 2) + s[N-1];
    }
    
    vector<string> wordsAbbreviation(vector<string>& words) {
        int N = words.size();
        unordered_map<string, vector<IndexedWord>> groups;
        vector<string> result(N);
        
        int index = 0;
        for (string s : words) {
            string abbr = getAbbreviation(s, 0);
            if (groups.find(abbr) == groups.end()) {
                groups[abbr] = {};
            }
            groups[abbr].push_back(IndexedWord(s, index++));
        }
        
        for (auto it : groups) {
            vector<IndexedWord> group = it.second;
            Trie* root = new Trie();
            
            for (IndexedWord w : group) {
                Trie* cur = root;
                
                for (char c : w.word.substr(1)) {
                    
                    if (cur->children.find(c) == cur->children.end()) {
                        cur->children[c] = new Trie();
                    }
                    cur->count++;
                    cur = cur->children[c];
                }
            }
            
            for (IndexedWord w : group) {
                Trie* cur = root;
                int i = 1;
                
                for (char c : w.word.substr(1)) {
                    
                    if (cur->count == 1) break;
                    
                    cur = cur->children[c];
                    i++;
                }
                
                result[w.index] = getAbbreviation(w.word, i - 1);
            }
        }
        
        return result;
    }
};