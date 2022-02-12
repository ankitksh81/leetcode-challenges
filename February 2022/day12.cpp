/*
	Word Ladder
	https://leetcode.com/problems/word-ladder/
*/

// Solution 1: BFS

class Solution {
public:
    vector<string> getNeighbours(string &str) {
        vector<char> chars;
        for(char c: str) {
            chars.push_back(c);
        }
        vector<string> result;
        for(int i = 0; i < chars.size(); i++) {
            char temp = chars[i];
            for(char c = 'a'; c <= 'z'; c++) {
                chars[i] = c;
                string s(chars.begin(), chars.end());
                result.push_back(s);
            }
            chars[i] = temp;
        }
        return result;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> words;
        for(auto &word: wordList) {
            words.insert(word);
        }
        words.erase(beginWord);
        q.push(beginWord);
        
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++) {
                string curWord = q.front();
                q.pop();
                if(curWord == endWord) {
                    return level;
                }
                vector<string> neighbours = getNeighbours(curWord);
                for(string neighbour: neighbours) {
                    if(words.count(neighbour)) {
                        words.erase(neighbour);
                        q.push(neighbour);
                    }
                }
            }
        }
        return 0;
    }
};

// Solution 2: Bi-Directional BFS

class Solution {
public:
    vector<string> getNeighbours(string &str) {
        vector<char> chars;
        for(char c: str) {
            chars.push_back(c);
        }
        vector<string> result;
        for(int i = 0; i < chars.size(); i++) {
            char temp = chars[i];
            for(char c = 'a'; c <= 'z'; c++) {
                chars[i] = c;
                string s(chars.begin(), chars.end());
                result.push_back(s);
            }
            chars[i] = temp;
        }
        return result;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto &str: wordList) {
            words.insert(str);
        }
        if(!words.count(endWord)) {
            return 0;
        }
        unordered_set<string> beginSet, endSet;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int length = 1;
        while(!beginSet.empty() && !endSet.empty()) {
            if(beginSet.size() > endSet.size()) {
                unordered_set<string> temp = beginSet;
                beginSet = endSet;
                endSet = temp;
            }
            unordered_set<string> newBeginSet;
            for(string word: beginSet) {
                vector<string> neighbours = getNeighbours(word);
                for(string neighbour: neighbours) {
                    if(endSet.count(neighbour)) {
                        return length + 1;
                    }
                    if(words.count(neighbour)) {
                        newBeginSet.insert(neighbour);
                        words.erase(neighbour);
                    }
                }
            }
            beginSet = newBeginSet;
            length++;
        }
        return 0;
    }
};