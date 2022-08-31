/*
	Pacific Atlantic Water Flow
	https://leetcode.com/problems/pacific-atlantic-water-flow/
*/

// Solution: DFS

class Solution {
    int M, N;
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<bool>> pacific, atlantic;
public:
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& grid) {
        grid[r][c] = true;
        for (auto dir : dirs) {
            int x = r + dir[0];
            int y = c + dir[1];
            
            if (x < 0 || x >= M || y < 0 || y >= N) continue;
            if (grid[x][y]) continue;
            if (heights[x][y] < heights[r][c]) continue;
            dfs(x, y, heights, grid);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        M = heights.size(), N = heights[0].size();
        vector<vector<int>> res;
        
        vector<vector<bool>> pacific(M, vector<bool>(N, false));
        vector<vector<bool>> atlantic(M, vector<bool>(N, false));
        
        for (int i = 0; i < M; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, N - 1, heights, atlantic);
        }
        
        for (int i = 0; i < N; i++) {
            dfs(0, i, heights, pacific);
            dfs(M-1, i, heights, atlantic);
        }
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (pacific[i][j] == 1 && atlantic[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};