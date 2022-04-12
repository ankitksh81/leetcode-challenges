/*
	Game of Life
	https://leetcode.com/problems/game-of-life/
*/

// Solution:

class Solution {
    int dirs[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
                     {1, 1}, {-1, -1}, {1, -1}, {-1 , 1}};
public:
    int solve(vector<vector<int>> &board, int r, int c) {
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        
        for(auto dir : dirs) {
            int x = r + dir[0];
            int y = c + dir[1];
            
            if(x < 0 || y < 0 || x >= m || y >= n) {
                continue;
            }
            
            if(board[x][y] == 1) {
                cnt++;
            }
        }
        
        if(board[r][c]) {
            if(cnt < 2 || cnt > 3) {
                return 0;
            }
            return 1;
        }
        else {
            if(cnt == 3) {
                return 1;
            }
        }
        return 0;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = solve(board, i, j);
            }
        }
        board = ans;
    }
};

// Solution 2: Constant Space

class Solution {
    int dirs[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
                     {1, 1}, {-1, -1}, {1, -1}, {-1 , 1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                for(auto dir : dirs) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    
                    if((x < m && x >= 0) && (y < n && y >= 0) && abs(board[x][y]) == 1) {
                        liveNeighbors++;
                    }
                }
                // Rule 1 or Rule 3
                if((board[i][j] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = -1;
                }
                
                // Rule 4
                if(board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 2;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] > 0) {
                    board[i][j] = 1;
                }
                else {
                    board[i][j] = 0;
                }
            }
        }
    }
};