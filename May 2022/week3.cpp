/*
	Number of Distinct Islands
	https://leetcode.com/problems/number-of-distinct-islands/
*/

// Solution: DFS

class Solution {
    unordered_set<string> distinctIslands;
    vector<vector<int>> grid;
    vector<vector<bool>> visited;
    int m, n;
    string curIsland;
public:
    void dfs(int r, int c, char dir) {
        if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || grid[r][c] == 0) {
            return;
        }
        
        visited[r][c] = true;
        curIsland += dir;
        
        dfs(r + 1, c, 'D');
        dfs(r - 1, c, 'U');
        dfs(r, c + 1, 'R');
        dfs(r, c - 1, 'L');
        
        curIsland += '0';
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                curIsland = "";
                dfs(i, j, '0');
                if(curIsland != "") {
                    distinctIslands.insert(curIsland);
                }
            }
        }
        
        return distinctIslands.size();
    }
};