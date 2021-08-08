// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3874/


// Solution 1:

class DSU {
    vector<int> parent;    
    public:
    DSU(int n) {
        parent.resize(n, -1);
    }
    int getParent(int a) {
        return (parent[a] == -1 ? a : getParent(parent[a]));
    }
    void merge(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if(a > b)
            swap(a, b);
        if(a != b)
            parent[b] = a;
    }
};

const int SEP = 500;

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int i, j, m = matrix.size(), n = matrix[0].size();
        map<int, vector<int>> mp;
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for(i=0; i<m; i++)
            for(j=0; j<n; j++) {
                int index = i * SEP + j;
                mp[matrix[i][j]].push_back(index);
            }
        vector<int> max_x(m, 0), max_y(n, 0);
        for(auto rec : mp) {
            auto &indexes = rec.second;
            DSU dsu(m + SEP + n);
            for(auto index : indexes) {
                int x = index / SEP;
                int y = index % SEP;
                dsu.merge(x, y + SEP);
            }
            unordered_map<int, vector<int>> partitions;
            for(auto index : indexes) {
                int p = dsu.getParent(index / SEP);
                partitions[p].push_back(index);
            }
            for(auto partition : partitions) {
                auto &a = partition.second;
                int x_rank = 0, y_rank = 0;
                for(i=0; i<a.size(); i++) {
                    int x = a[i] / SEP;
                    int y = a[i] % SEP;
                    x_rank = max(x_rank, max_x[x]);
                    y_rank = max(y_rank, max_y[y]);
                }
                int rank = max(x_rank, y_rank) + 1;
                for(i=0; i<a.size(); i++) {
                    int x = a[i] / SEP;
                    int y = a[i] % SEP;
                    ret[x][y] = rank;
                    max_x[x] = rank;
                    max_y[y] = rank;
                }
            }
        }
        return ret;
    }
};

// Solution 2:

class Solution {
    public:
        vector<int> p;
        int f(int x) {
            if (p[x] == x) return x;
            return p[x] = f(p[x]);
        }
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        vector<vector<int>> all;
        int R = matrix.size();
        int C = matrix[0].size();
        map<int, vector<pair<int, int>>> m;
        p.resize(R+C);
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                m[matrix[i][j]].push_back({i, j});
            }
        }
        vector<vector<int>> ans(R, vector<int>(C));
        vector<int> Max(R+C);
        vector<int> rmax(R);
        vector<int> cmax(C);
        for (auto &it : m) {
            for (auto &it2 : it.second) {
                // Don't want to reset the whole parent everytime
                // We just need to reset the rows and columns 
                // we're going to use this time
                p[it2.first] = it2.first;
                Max[it2.first] = rmax[it2.first];
                p[it2.second+R] = it2.second+R;
                Max[it2.second+R] = cmax[it2.second];
            }
            for (auto &it2 : it.second) {
                // Union row and column together
                // Also the max rank
                int a = f(it2.first), b = f(it2.second+R);
                if (a != b) {
                    p[a] = b;
                    Max[b] = max(Max[a], Max[b]);
                }
            }
            // Perform update in another loop since we only 
            // know the max rank after union-find
            for (auto &it2 : it.second) {
                int x = Max[f(it2.first)]+1;
                ans[it2.first][it2.second] = x;
                rmax[it2.first] = x;
                cmax[it2.second] = x;
            }
        }
        return ans;
    }
};