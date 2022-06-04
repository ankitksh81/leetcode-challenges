/*
	N-Queens
	https://leetcode.com/problems/n-queens/
*/

// Solution: Backtracking

class Solution {
    vector<vector<string>> result;
    
    bool isSafe(vector<string>& board, int i, int j, int n) {
        for (int r = 0; r < i; r++) {
            if (board[r][j] == 'Q') return false;
        }
        
        int x = i, y = j;
        while(x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        
        x = i, y = j;
        while (x >= 0 && y < n) {
            if (board[x][y] == 'Q') return false;
            x--;
            y++;
        }
        
        return true;
    }
public:
    bool nQueen(int n, vector<string>& board, int i) {
        if (i == n) {
            result.push_back(board);
            return false;
        }
        
        for (int j = 0; j < n; j++) {
            if (isSafe(board, i, j, n)) {
                board[i][j] = 'Q';
                nQueen(n, board, i+1);
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        nQueen(n, board, 0);
        
        return result;
    }
};