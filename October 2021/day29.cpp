/*
    Rotting Oranges
    https://leetcode.com/problems/rotting-oranges/
*/

// Solution:

class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || grid[i][j] == 2) {
            return false;
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0, fine = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    fine++;
                }
            }
        }
        while(!q.empty()) {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                auto it = q.front();
                q.pop();
                int x = it.first;
                int y = it.second;
                
                for(int k = 0; k < 4; k++) {
                    int X = x + dx[k];
                    int Y = y + dy[k];
                    if(isValid(grid, X, Y)){
                        q.push({X, Y});
                        grid[X][Y] = 2;
                        fine--;
                    }
                }
            }
            
            if(!q.empty()) {
                time++;
            }
        }
        
        if(fine > 0) {
            return -1;
        }
        return time;
    }
};