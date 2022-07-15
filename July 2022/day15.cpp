/*
	Max Area of Island
	https://leetcode.com/problems/max-area-of-island/
*/

// Solution: DFS

class Solution {
    vector<vector<bool>> vis;
    int dirs[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
public:
    bool isSafe(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            vis[i][j] || grid[i][j] == 0) {
            return false;
        }
        return true;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j) {
        vis[i][j] = true;
        
        int curArea = 1;
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            
            if (isSafe(grid, x, y)) {
                curArea += dfs(grid, x, y);
            }
        }
        
        return curArea;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vis = vector<vector<bool>>(M, vector<bool>(N));
        
        int maxArea = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] && !vis[i][j]) {
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
};