// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3987/


// Solution:

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int x = it[0];
            int y = it[1];
            
            if(x < 0 || x >= m || y < 0 || y >= n) {
                continue;
            } 
            
            int steps = it[2];
            int obs = it[3];
            
            if(x == m-1 && y == n-1) {
                return steps;
            }
            
            
            if(grid[x][y] == 1) {
                if(obs > 0) {
                    obs--;
                }
                else {
                    continue;
                }
            }
            
            if(vis[x][y] != -1 && vis[x][y] >= obs) {
                continue;
            }
            
            vis[x][y] = obs;
            
            q.push({x+1, y, steps+1, obs});
            q.push({x-1, y, steps+1, obs});
            q.push({x, y+1, steps+1, obs});
            q.push({x, y-1, steps+1, obs});
        }
        
        return -1;
    }
};