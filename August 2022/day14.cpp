/*
	Word Ladder II
	https://leetcode.com/problems/word-ladder-ii/
*/

// Solution: BFS + Backtracking

class Solution {
public:
    
    bool check(string word1, string word2) {
        int cnt = 0;
        for (int i = 0; i < word1.size(); i++) {
            if (word1[i] != word2[i]) cnt++;
        }
        if (cnt == 1) return true;
        return false;
    }
    
    void backTrack(map<string,int>& dis, string CurrWord, vector<vector<string>>& result, vector<string>& path, vector<string>& wordList, string& beginWord) {
        if (dis[CurrWord] == 1) {
            path.push_back(beginWord);
            reverse(path.begin(), path.end());
            result.push_back(path);
            reverse(path.begin(), path.end());
            path.pop_back();
            return;
        }
        
        for (int i = 0; i < wordList.size(); i++) {
            if (dis[wordList[i]] + 1 == dis[CurrWord] && check(CurrWord, wordList[i])) {
                path.push_back(wordList[i]);
                backTrack(dis, wordList[i], result, path, wordList, beginWord);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string,int> dis;
        for (int i = 0; i < wordList.size(); i++) dis[wordList[i]] = -1 ;
        queue <string> q;
        dis[beginWord] = 0;
        q.push(beginWord);
        while(!q.empty()) {
            string u = q.front();
            q.pop();
            for (int i = 0 ; i < u.size() ; i++) {
                string v = u;
                for (char j = 'a' ; j <= 'z' ; j++) {    
                    v[i] = j;
                    if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                    }
                }
            }
        }
        
        vector<vector<string>> result ;
        
        if (dis[endWord] <= 0) return result;
        else {
            vector<string> path;
            path.push_back(endWord);
            backTrack(dis, endWord, result, path, wordList, beginWord);
            return result;
        }
    }
};