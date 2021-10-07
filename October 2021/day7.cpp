/*
    Word Search
    https://leetcode.com/problems/word-search/
*/

// Solution:

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
public:
    bool isValid(vector<vector<char>>& board, int i, int j) {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j, int idx, string &word) {
        if(idx == word.length()-1) {
            return true;
        }
        char val = board[i][j];
        board[i][j] = '#';
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(isValid(board, x, y) && board[x][y] == word[idx+1]) {
                if(solve(board, x, y, idx+1, word)) {
                    return true;
                }
            }
        }
        board[i][j] = val;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = word.length();
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(solve(board, i, j, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};