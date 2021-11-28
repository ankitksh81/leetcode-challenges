/*
    All paths from source to target
    https://leetcode.com/problems/all-paths-from-source-to-target/
*/

// Solution: DFS

class Solution {
public:
    void findPaths(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& cur_path, int node) {
        if(node == graph.size()-1) {
            paths.push_back(cur_path);
        }
        
        for(auto it: graph[node]) {
            vector<int> res = cur_path;
            res.push_back(it);
            findPaths(graph, paths, res, it);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> cur_path{0};
        findPaths(graph, paths, cur_path, 0);
        
        return paths;
    }
};