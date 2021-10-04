/*
    Island Perimeter
    https://leetcode.com/problems/island-perimeter/
*/

// Solution 1:

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return false;
        }
        return true;
    }
    
    int findAdj(vector<vector<int>>& grid, int i, int j) {
        int cnt = 0;
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(isValid(grid, x, y)) {
                cnt++;
            }
        }
        return cnt;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int perimeter = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1){
                    int adj = findAdj(grid, i, j);
                    perimeter += (4 - adj);
                }
            }
        }
        
        return perimeter;
    }
};


// Solution 2:

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0, cnt1 = 0, cnt2 = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    cnt1++;
                    if(i != 0 && grid[i-1][j] == 1)
                        cnt2++;
                    if(j != 0 && grid[i][j-1] == 1)
                        cnt2++;
                }
            }
        }
        
        perimeter = (4 * cnt1) - (2 * cnt2);
        return perimeter;
    }
};