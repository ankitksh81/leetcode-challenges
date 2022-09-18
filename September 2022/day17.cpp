/*
	Palindrome Pairs
	https://leetcode.com/problems/palindrome-pairs/
*/

// Solution 1: Hashmap (faster then Solution 2)

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<int, unordered_map<string, int>> mp;
        for (int i = 0; i < words.size(); i++) {
            string revWord = string (words[i].rbegin(), words[i].rend());
            mp[words[i].length()][revWord] = i;
        }
        
        auto hasRemPalindrome = [&](string &str, int i, int j) -> bool {
            while (i < j) {
                if (str[i] != str[j]) return false;
                i++;
                j--;
            }
            
            return true;
        };
        
        vector<vector<int>> pairs;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            
            for (auto &it : mp) {
                if (it.first > word.length()) break;
                
                if (it.first == word.length()) {
                    if (it.second.find(word) != it.second.end() && it.second[word] != i) {
                        pairs.push_back({i, it.second[word]});
                    }
                    
                    continue;
                }
                
                if (hasRemPalindrome(word, 0, words[i].length()-1 - it.first) && 
                    it.second.find(words[i].substr(words[i].length() - it.first)) != it.second.end()) {
                    pairs.push_back({it.second[words[i].substr(words[i].length() - it.first)], i});
                }
                
                if (hasRemPalindrome(word, words[i].length() - (words[i].length() - it.first), words[i].length() - 1) && 
                    it.second.find(words[i].substr(0, it.first)) != it.second.end()) {
                    pairs.push_back({i, it.second[words[i].substr(0, it.first)]});
                }
            }
        }
        
        return pairs;
    }
};


// Solution 2: Trie

struct Trie {
    int wordEnding;
    unordered_map<char, Trie*> child;
    vector<int> palindromePrefixRemaining;
    
    Trie () : wordEnding(-1) {}
};

class Solution {
    bool hasPalindromeRemaining(string &s, int idx) {
        int l = idx, r = s.length()-1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        
        return true;
    }
    
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie* trie = new Trie();
        
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            string revWord = word;
            reverse(revWord.begin(), revWord.end());
            
            Trie* root = trie;
            for (int j = 0; j < word.length(); j++) {
                if (hasPalindromeRemaining(revWord, j)) {
                    root->palindromePrefixRemaining.push_back(i);
                }
                char ch = revWord[j];
                if (root->child.find(ch) == root->child.end()) {
                    root->child[ch] = new Trie();
                }
                root = root->child[ch];
            }
            
            root->wordEnding = i;
        }
        
        vector<vector<int>> pairs;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            
            bool isNull = false;
            Trie* root = trie;
            for (int j = 0; j < word.length(); j++) {
                if (root->wordEnding != -1 && hasPalindromeRemaining(word, j)) {
                    pairs.push_back({i, root->wordEnding});
                }
                char ch = word[j];
                if (root->child.find(ch) == root->child.end()) {
                    isNull = true;
                    break;
                }
                root = root->child[ch];
            }
            
            if (isNull) continue;
            
            if (root->wordEnding != -1 && root->wordEnding != i) {
                pairs.push_back({i, root->wordEnding});
            }
            
            for (int other : root->palindromePrefixRemaining) {
                pairs.push_back({i, other});
            }
        }
        
        return pairs;
    }
};