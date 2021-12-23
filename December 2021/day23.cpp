/*
    Course Schedule II
    https://leetcode.com/problems/course-schedule-ii
*/

// Solution: Topological sort

class Solution {
public:
    bool bfs(int N, vector<int> adj[], vector<int>& topo, vector<int>& inDeg) {
        queue<int> q;
        for(int i = 0; i < N; i++) {
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        
        while(!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            cnt++;
            for(auto it: adj[node]) {
                inDeg[it]--;
                if(inDeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        if(cnt == N){ // doesn't have a cycle if (cnt == N)
            return false;
        }
        return true;
    }
    
    vector<int> topologicalSort(int N, vector<int> adj[], vector<int>& inDeg) {
        vector<int> topo;
        if(!bfs(N, adj, topo, inDeg)){
            return topo;
        }
        return {};
    }
    
    vector<int> findOrder(int N, vector<vector<int>>& A) {
        int m = A.size();
        vector<int> adj[N];
        vector<int> inDeg(N, 0);
        for(int i = 0; i < m; i++){
            adj[A[i][1]].push_back(A[i][0]);
            inDeg[A[i][0]]++;
        }
        return topologicalSort(N, adj, inDeg);
    }
};