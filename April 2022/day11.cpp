/*
	Shift 2D Grid
	https://leetcode.com/problems/shift-2d-grid/
*/

// Solution: Modulo Arithmetic

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> newGrid(m, vector<int>(n));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int newCol = (j + k) % n;
                int cnt = (j + k) / n;
                int newRow = (i + cnt) % m;
                newGrid[newRow][newCol] = grid[i][j];
            }
        }
        
        return newGrid;
    }
};