/*
	Path With Maximum Minimum Value
	https://leetcode.com/problems/path-with-maximum-minimum-value/
*/

// Solution 1: Binary Search + DFS

class Solution {
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool visited[101][101];
public:
    int pathExists(vector<vector<int>>& grid, int val, int r, int c) {
        if(r == grid.size()-1 && c == grid[0].size()-1) {
            return true;
        }
        
        visited[r][c] = true;
        for(auto dir : dirs) {
            int x = r + dir[0];
            int y = c + dir[1];
            
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !visited[x][y] && grid[x][y] >= val) {
                if(pathExists(grid, val, x, y)) {
                    return true;
                }
            }
         }
        
        return false;
    }
    
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int left = 0, right = min(grid[0][0], grid[m-1][n-1]);
        while(left < right) {
            int mid = (left + right + 1) / 2;
            memset(visited, false, sizeof(visited));
            
            if(pathExists(grid, mid, 0, 0)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};

// Solution 2: Union Find

class Solution {
    vector<int> uf;
    vector<int> rank;

    int find(int x) {
        if (x != uf[x]) {
            uf[x] = find(uf[x]);
        }
        return uf[x];
    }  

    void uni(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                uf[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                uf[rootX] = rootY;
            } else {
                uf[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

public:    
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();

        vector<vector<int>> vals;

        vector<vector<int>> dirs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        rank = vector<int>(R * C, 1);
        uf = vector<int>(R * C, 0);
        
        vector<vector<bool>> visited(R, vector<bool>(C));

        for (int row = 0; row < R; ++row) {
            for (int col = 0; col < C; ++col) {
                uf[row * C + col] = row * C + col;
                vals.push_back({grid[row][col], row, col});
            }
        }

        sort(vals.begin(), vals.end(), greater<vector<int>>());
        for (vector<int>& curGrid : vals) {
            int curRow = curGrid[1], curCol = curGrid[2];
            int curPos = curRow * C + curCol;

            visited[curRow][curCol] = true;
            for (vector<int> dir : dirs) {
                int newRow = curRow + dir[0], newCol = curCol + dir[1];
                int newPos = newRow * C + newCol;

                if (newRow >= 0 && newRow < R && newCol >= 0 && newCol < C 
                    && visited[newRow][newCol]) {
                    uni(curPos, newPos);
                }
            }

            if (find(0) == find(R * C - 1)) { 
                return grid[curRow][curCol];
            }
        }
        return 0;
    }
};
