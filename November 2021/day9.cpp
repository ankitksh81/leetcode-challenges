/*
    Number of valid words for each puzzle
    https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/
*/

// Solution 1: Using bitmask

class Solution {
public:
    int bitmask(const string &word) {
        /* Build a bitmask of chars to represent each word */
        int mask = 0;
        for(char c: word) {
            mask |= 1 << (c - 'a');
        }
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> wordCount;
        
        for(string &word: words) {
            wordCount[bitmask(word)]++;
        }
        
        vector<int> res;
        for(string &puzzle: puzzles) {
            int first = 1 << (puzzle[0] - 'a');
            int count = wordCount[first];
            
            /* Make bitmask but ignore the first char since it must always be there. */
            int mask = bitmask(puzzle.substr(1));
            
            /* Iterate over the submask */
            for(int submask = mask; submask; submask = (submask - 1) & mask) {
                /* Add first character */
                count += wordCount[submask | first];
            }
            
            res.push_back(count);
        }
        
        return res;
    }
};

// Solution 2: Using trie

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int Size = 26;
        vector<vector<int>> trie = {vector<int>(Size)};
        vector<int> count = {0};
        
        for(string word: words) {
            sort(word.begin(), word.end());
            word.erase(unique(word.begin(), word.end()), word.end());
            
            if(word.size() <= 7) {
                int node = 0;
                
                for(char &c: word) {
                    int i = c - 'a';
                    
                    if(trie[node][i] == 0) {
                        trie.push_back(vector<int>(Size));
                        count.push_back(0);
                        trie[node][i] = trie.size() - 1;
                    }
                    
                    node = trie[node][i];
                }
                count[node]++;
            }
        }
        
        function<int(int, bool, string&)> dfs = [&](int node, bool hasFirst, string& puzzle) {
            int total = hasFirst ? count[node] : 0;
            for(char &c: puzzle) {
                int i = c - 'a';
                if(trie[node][i]) {
                    total += dfs(trie[node][i], hasFirst || (c == puzzle[0]), puzzle);
                }
            }
            return total;
        };
        vector<int> res;
        for(string &puzzle: puzzles) {
            res.push_back(dfs(0, false, puzzle));
        }
        
        return res;
    }
};