// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3963/


// Solution 1:

class Solution {
public:
    int dfs(int v, int par, vector<int> adj[], vector<int> &subtree) {
        int cur = 0;
        for(auto u: adj[v]) {
            if(u != par) {
                cur += dfs(u, v, adj, subtree);
                cur += subtree[u];
                subtree[v] += subtree[u];
            }
        }
        return cur;
    }

    void dfs(int v, int par, vector<int> adj[], vector<int> &ans, vector<int> &subtree, int now) {
        ans[v] = now;
        for(auto u: adj[v]) {
            if(u != par) {
                dfs(u, v, adj, ans, subtree, now - subtree[u] + subtree[0] - subtree[u]);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n), subtree(n, 1), adj[n];

        for(auto v: edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        int root_ans = dfs(0, -1, adj, subtree);
        dfs(0, -1, adj, ans, subtree, root_ans);

        return ans;
    }
};

// Solution 2:

class Solution {
public:
    vector<vector<int>> v;
    vector<int> counter, res;
    
    void dfs(int i, int p = -1) {
        for(auto u : v[i]) {
        if(u == p) {
            continue;
        }
        dfs(u, i);
        counter[i] += counter[u];
            res[i] += res[u] + counter[u];
        }
        counter[i] += 1;
    }
    
        
   void dfs2(int i, int n, int p = -1) {
       for(auto u : v[i]) {
           if(u == p) {
               continue;
           }
           res[u] = res[i] - counter[u] + n - counter[u];
           dfs2(u, n, i);
       }
   }
    
   vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
       v.resize(n);
       for(int i = 0; i < n-1; i++) {
           int a = edges[i][0], b = edges[i][1];
           v[a].push_back(b);
           v[b].push_back(a);
       }
       res.resize(n);
       counter.resize(n);
       dfs(0);
       dfs2(0, n);
       return res;
   }
}