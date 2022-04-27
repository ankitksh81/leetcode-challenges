/*
	Smallest String Withh Swaps
	https://leetcode.com/problems/smallest-string-with-swaps/
*/

// Solution 1: DFS

class Solution {
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
public:
    void dfs(string &s, int vertex, vector<char>& chars, vector<int>& indices) {
        chars.push_back(s[vertex]);
        indices.push_back(vertex);
        
        visited[vertex] = true;
        
        for(int neighbor : adj[vertex]) {
            if(!visited[neighbor]) {
                dfs(s, neighbor, chars, indices);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        for(auto &edge : pairs) {
            int u = edge[0], v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0; i < s.length(); i++) {
            if(!visited[i]) {
                vector<char> chars;
                vector<int> indices;
                
                dfs(s, i, chars, indices);
                sort(chars.begin(), chars.end());
                sort(indices.begin(), indices.end());
                
                for(int i = 0; i < chars.size(); i++) {
                    s[indices[i]] = chars[i];
                }
            }
        }
        
        return s;
    }
};

// Solution 2: Union Find

class UF {
public:
    vector<int> par;
    UF(int n) {
        for(int i = 0; i < n; i++) {
            par.push_back(i);
        }
    }
    
    int find(int a) {
        if(par[a] == a)
            return a;
        return par[a] = find(par[a]);
    }
    
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        
        if(a != b)
            par[a] = b;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        UF uf(n);
        
        for(auto edge : pairs) {
            int a = edge[0];
            int b = edge[1];
            
            uf.join(a, b);
        }
        
        unordered_map<int, vector<int>> rootToComp;
        for(int i = 0; i < s.length(); i++) {
            int root = uf.find(i);
            rootToComp[root].push_back(i);
        }
        
        string ans(s.length(), ' ');
        
        for(auto cmp : rootToComp) {
            vector<int> idx = cmp.second;
            vector<int> chars;
            
            for(int i = 0; i < idx.size(); i++) {
                chars.push_back(s[idx[i]]);
            }
            
            sort(chars.begin(), chars.end());
            for(int i = 0; i < idx.size(); i++) {
                ans[idx[i]] = chars[i];
            }
        }
        return ans;
    }
};