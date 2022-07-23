/*
	All Paths from Source Lead to Destination
	https://leetcode.com/problems/all-paths-from-source-lead-to-destination/
*/

// Solution: DFS

class Solution {
public:
    bool dfs(vector<int> adj[], vector<int> &vis, int source, int dest) {
        if (adj[source].empty()) return source == dest;
        if (vis[source] != -1) return vis[source];
        
        vis[source] = 0;
        
        for (int neighbor : adj[source]) {
            if (!dfs(adj, vis, neighbor, dest)) return false;
        }
        
        return vis[source] = true;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        vector<int> vis(n, -1);
        
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        
        return dfs(adj, vis, source, destination);
    }
};