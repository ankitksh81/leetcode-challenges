/*
	Shortest Path in Binary Matrix
	https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/

// Solution: BFS

class Solution {
    int dirs[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
public:
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size();
        if (x < 0 or y < 0 or x >= n or y >= n or grid[x][y] != 0) {
            return false;
        }
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (n == 1 && grid[0][0] == 0)  return 1;
        if (grid[0][0] == 1 or grid[n-1][n-1] == 1) return -1;
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        while(!q.empty()) {
            pair<int, int> cur = q.front(); q.pop();
            int x = cur.first;
            int y = cur.second;
            
            if(x == n-1 && y == n-1) {
                return grid[x][y];
            }
            
            for(auto dir : dirs) {
                int r = x + dir[0];
                int c = y + dir[1];
                
                if(isValid(grid, r, c)) {
                    grid[r][c] = 1 + grid[x][y];
                    q.push({r, c});
                }
            }
        }
        
        return -1;
    }
};