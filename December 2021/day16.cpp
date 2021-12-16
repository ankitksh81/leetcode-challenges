/*
    Minimum height trees
    https://leetcode.com/problems/minimum-height-trees/
*/

// Solution:

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n < 2) {
            vector<int> nodes;
            for(int i = 0; i < n; i++) {
                nodes.push_back(i);
            }
            return nodes;
        }
        
        vector<int> adj[n];
        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // find first layer of leaf nodes
        vector<int> leaves;
        for(int i = 0; i < n; i++) {
            if(adj[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        
        // remove the first layer until we reach the inner most nodes(centroid)
        int remaining_nodes = n;
        while(remaining_nodes > 2) {
            remaining_nodes -= leaves.size();
            // initialize new vector to store next layer of leaf nodes
            vector<int> newLeaves;
            
            // remove current layer of leaf nodes along with the edges
            for(auto leaf: leaves) {
                int neighbor = adj[leaf][0];
                // find the position of the current leaf node in it's only
                // neighbor and then erase the edge to the current leaf node
                auto it = find(adj[neighbor].begin(), adj[neighbor].end(), leaf);
                adj[neighbor].erase(it);
                
                // if after removing the previous leaf node becomes a new
                // leaf node then add it to newLeaves
                if(adj[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }
            // update the new leaf nodes as the outer most leaf nodes
            leaves = newLeaves;
        }
        
        return leaves;
    }
};