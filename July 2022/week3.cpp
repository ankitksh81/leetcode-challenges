/*
	Shortest Distance to Target Color
	https://leetcode.com/problems/shortest-distance-to-target-color/
*/

// Solution 1: Binary Search

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int N = colors.size();
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < N; i++) {
            pos[colors[i]].push_back(i);
        }
        
        vector<int> result;
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0], color = queries[i][1];
            if (pos.find(color) == pos.end()) {
                result.push_back(-1);
                continue;
            }
            
            vector<int> &curPos = pos[color];
            int j = lower_bound(curPos.begin(), curPos.end(), idx) - curPos.begin();
            
            if (j == 0) {
                result.push_back(curPos[j] - idx);
            }
            else if (j == curPos.size()) {
                result.push_back(idx - curPos[j - 1]);
            }
            else {
                int l = idx - curPos[j - 1];
                int r = curPos[j] - idx;
                result.push_back(min(l, r));
            }
        }
        
        return result;
    }
};


// Solution 2: Dynamic Programming

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<int> ones(n, n + 1), two(n, n + 1), three(n, n + 1);
        
        ones[0] = colors[0] == 1 ? 0 : n + 1;
        two[0] = colors[0] == 2 ? 0 : n + 1;
        three[0] = colors[0] == 3 ? 0 : n + 1;
        
        for (int i = 1; i < n; i++) {
            if (colors[i] == 1) {
                ones[i] = 0;
                two[i] = two[i - 1] + 1;
                three[i] = three[i - 1] + 1;
            } else if (colors[i] == 2) {
                two[i] = 0;
                ones[i] = ones[i - 1] + 1;
                three[i] = three[i - 1] + 1;
            } else {
                three[i] = 0;
                ones[i] = ones[i - 1] + 1;
                two[i] = two[i - 1] + 1;
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            ones[i] = min(ones[i], ones[i + 1] + 1);
            two[i] = min(two[i], two[i + 1] + 1);
            three[i] = min(three[i], three[i + 1] + 1);
        }
        
        vector<int> result(queries.size(), -1);
        
        for (int i = 0; i < queries.size(); i++) {
            vector<int>& query = queries[i];
            if (query[1] == 1) result[i] = ones[query[0]] > n ? -1 : ones[query[0]]; 
            if (query[1] == 2) result[i] = two[query[0]] > n ? -1 : two[query[0]]; 
            if (query[1] == 3) result[i] = three[query[0]] > n ? -1 : three[query[0]]; 
        }
        
        return result;
    }
};