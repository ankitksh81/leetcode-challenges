/*
	Number of Islands
	https://leetcode.com/problems/number-of-islands/
*/

// Solution: DFS

class Solution {
    vector<vector<char>> grid;
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    void dfs(int r, int c) {
        grid[r][c] = '0';
        for (auto dir : dirs) {
            int x = r + dir[0];
            int y = c + dir[1];
            
            if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == '1') {
                dfs(x, y);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        int islands = 0;
        
        for (int i = 0; i < this->grid.size(); i++) {
            for (int j = 0; j < this->grid[0].size(); j++) {
                if (this->grid[i][j] == '1') {
                    dfs(i, j);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};