/*
	Evaluate Division
	https://leetcode.com/problems/evaluate-division/
*/

// Solution: DFS

class Solution {
    double find(unordered_map<string, unordered_map<string, double>>& adj, string a, string b, unordered_set<string>& visited) {
        if(adj[a].find(b) != adj[a].end()) {
            return adj[a][b];
        }
        
        for(auto it : adj[a]) {
            if(visited.find(it.first) == visited.end()) {
                visited.insert(it.first);
                double dist = find(adj, it.first, b, visited);
                
                if(dist) {
                    adj[a][b] = it.second * dist;
                    return adj[a][b];
                }
            }
        }
        return 0;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int size = equations.size();
        vector<double> result(queries.size());
        unordered_map<string, unordered_map<string, double>> adj;
        
        for(int i = 0; i < size; i++) {
            string u = equations[i][0], v = equations[i][1];
            adj[u][v] = values[i];
            adj[v][u] = double(1 / values[i]);
        }
        
        unordered_set<string> visited;
        for(int i = 0; i < queries.size(); i++) {
            string a = queries[i][0], b = queries[i][1];
            double val = find(adj, a, b, visited);
            
            if(!val) {
                result[i] = -1.0;
            }
            else {
                result[i] = val;
            }
            
            visited.clear();
        }
        
        return result;
    }
};