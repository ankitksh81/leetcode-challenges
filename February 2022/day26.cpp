/*
	Shortest Path Visiting All Nodes
	https://leetcode.com/problems/shortest-path-visiting-all-nodes/
*/

// Solution 1: DFS + Memoization

class Solution {
    int cache[13][(1 << 13)];
    int endingMask;
public:
    int findShortestPathLength(int node, int mask, vector<vector<int>>& graph) {
        if(cache[node][mask] != 0) {
            return cache[node][mask];
        }
        
        if((mask & (mask - 1)) == 0) {
            return 0;
        }
        
        cache[node][mask] = INT_MAX - 1;
        for(int neighbor : graph[node]) {
            if((mask & (1 << neighbor)) != 0) {
                int alreadyVisited = findShortestPathLength(neighbor, mask, graph);
                int notVisited = findShortestPathLength(neighbor, mask ^ (1 << node), graph);
                int betterOption = min(alreadyVisited, notVisited);
                cache[node][mask] = min(cache[node][mask], 1 + betterOption);
            }
        }
        
        return cache[node][mask];
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        endingMask = (1 << n) - 1;
        memset(cache, 0, sizeof(cache));
        
        int best = INT_MAX;
        for(int node = 0; node < n; node++) {
            best = min(best, findShortestPathLength(node, endingMask, graph));
        }
        
        return best;
    }
};

// Solution 2: BFS

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int endingMask = (1 << n) - 1;
        if(n == 1) {
            return 0;
        }
        
        vector<vector<bool>> seen(n, vector<bool>(endingMask));
        queue<pair<int, int>> q;
        int steps = 0;
        
        for(int i = 0; i < n; i++) {
            q.push({i, (1 << i)});
            seen[i][(1 << i)] = true;
        }
        
        while(!q.empty()) {
            queue<pair<int, int>> nextQ;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto curPair = q.front();
                q.pop();
                int node = curPair.first;
                int mask = curPair.second;
                
                for(int neighbor : graph[node]) {
                    int nextMask = mask | (1 << neighbor);
                    if(nextMask == endingMask) {
                        return 1 + steps;
                    }
                    
                    if(!seen[neighbor][nextMask]) {
                        seen[neighbor][nextMask] = true;
                        nextQ.push({neighbor, nextMask});
                    }
                }
            }
            steps++;
            q = nextQ;
        }
        
        return -1;
    }
};