/*
	N-Queens II
	https://leetcode.com/problems/n-queens-ii/
*/

// Solution: Backtracking

class Solution {
    int result;
public:
    bool isSafe(int n, int i, int j, vector<string>& board) {
        for (int r = 0; r < i; r++) {
            if (board[r][j] == 'Q') return false;
        }
        
        int x = i, y = j;
        while (x >= 0 && y >= 0) {
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
    
    bool nQueen(int n, vector<string>& board, int i) {
        if (i == n) {
            result++;
            return false;
        }
        
        for (int j = 0; j < n; j++) {
            if (isSafe(n, i, j, board)) {
                board[i][j] = 'Q';
                nQueen(n, board, i+1);
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    int totalNQueens(int n) {
        if (n == 1) return 1;
        if (n <= 3) return 0;
        result = 0;
        vector<string> board(n, string(n, '.'));
        nQueen(n, board, 0);
        return result;
    }
};