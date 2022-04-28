/*
	Path With Minimum Effort
	https://leetcode.com/problems/path-with-minimum-effort/
*/

// Solution 1: Modified Dijkstra's Algorithm

class Cell {
public:
    int x, y;
    int diff;
    
    Cell(int x, int y, int diff) : x(x), y(y), diff(diff) {}

};

struct Comparator {
    bool operator()(Cell const &p1, Cell const &p2) {
        return p2.diff < p1.diff;
    }
};

class Solution {
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool isValidCell(int x, int y, int m, int n) {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        diff[0][0] = 0;
        
        priority_queue<Cell, vector<Cell>, Comparator> pq;
        pq.push(Cell(0, 0, diff[0][0]));
        
        while(!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();
            visited[cur.x][cur.y] = true;
            
            if(cur.x == m - 1 && cur.y == n-1) {
                return cur.diff;
            }
            
            for(auto dir : dirs) {
                int x = cur.x + dir[0];
                int y = cur.y + dir[1];
                
                if(isValidCell(x, y, m, n) && !visited[x][y]) {
                    
                    int curDiff = abs(heights[x][y] - heights[cur.x][cur.y]);
                    int maxDiff = max(curDiff, diff[cur.x][cur.y]);
                    
                    if(diff[x][y] > maxDiff) {
                        diff[x][y] = maxDiff;
                        pq.push(Cell(x, y, maxDiff));
                    }
                    
                }
            }
        }
        
        return diff[m-1][n-1];
    }
};

// Solution 2: Binary Search + BFS

class Cell {
public:
    int x, y;
    Cell (int x, int y) : x(x), y(y) {}
};

class Solution {
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool isValidCell(int x, int y, int m, int n) {
        return (x >= 0 && y >= 0 && x < m && y < n);
    }
    
    bool canReach(vector<vector<int>>& heights, int k) {
        int m = heights.size(), n = heights[0].size();
        queue<Cell> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push(Cell(0, 0));
        visited[0][0] = true;
        
        while(!q.empty()) {
            Cell cur = q.front();
            q.pop();
            
            if (cur.x == m - 1 && cur.y == n - 1) {
                return true;
            }
            
            for(auto dir : dirs) {
                int x = cur.x + dir[0];
                int y = cur.y + dir[1];
                
                if(isValidCell(x, y, m, n) && !visited[x][y]) {
                    int curDiff = abs(heights[x][y] - heights[cur.x][cur.y]);
                    
                    if(curDiff <= k) {
                        visited[x][y] = true;
                        q.push(Cell(x, y));
                    }
                }
            }
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        
        int l = 0, h = 1e6;
        int effort = h;
        
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(canReach(heights, mid)) {
                effort = min(effort, mid);
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        
        return effort;
    }
};