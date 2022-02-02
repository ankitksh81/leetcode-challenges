/*
	The Earliest Moment When Everyone Become Friends
	https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/
*/

// Solution 1: Union Find

class Solution {
    vector<int> parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [&](const vector<int>& a, const vector<int>& b){
            return a.front() < b.front();
        });
        
        parent.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        for(int i = 0; i < logs.size(); i++) {
            int x = find(logs[i][1]);
            int y = find(logs[i][2]);
            if(x != y) {
                n--;
                if(n == 1) {
                    return logs[i][0];
                }
                parent[y] = x;
            }
        }
        
        return -1;
    }
};

// Solution 2: Union Find

struct UF {
    vector<int> parent, rank;
    UF(int n) {
        parent.resize(n, -1);
        rank.resize(n);
    }
    
    int find(int x) {
        if(parent[x] == -1) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    bool join(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) {
            return false;
        }
        else {
            parent[x] = y;
        }
        if(rank[x] == rank[y]) {
            ++rank[x];
        }
        return true;
    }
};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        UF uf(n);
        for(auto &log: logs) {
            if(uf.join(log[1], log[2])) {
                n--;
            }
            if(n == 1) {
                return log[0];
            }
        }
        
        return -1;
    }
};