/*
	The Maze II
	https://leetcode.com/problems/the-maze-ii/
*/

// Solution: BFS

class Solution {
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[start[0]][start[1]] = 0;
        queue<vector<int>> q;
        q.push(start);
        
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int r = cur[0], c = cur[1];
            
            for (auto dir : dirs) {
                int x = r + dir[0];
                int y = c + dir[1];
                int cnt = 0;
                
                while (x >= 0 && y >= 0 && x < m && y < n && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                    cnt++;
                }
                
                int newX = x - dir[0], newY = y - dir[1];
                if (dist[r][c] + cnt < dist[newX][newY]) {
                    dist[newX][newY] = dist[r][c] + cnt;
                    q.push({newX, newY});
                }
            }
        }
        
        int x = destination[0], y = destination[1];
        return dist[x][y] == INT_MAX ? -1 : dist[x][y];
    }
};