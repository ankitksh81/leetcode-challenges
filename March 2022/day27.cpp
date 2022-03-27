/*
	The K Weakest Rows in a Matrix
	https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
*/

// Solution 1: Binary Search + Sorting

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int, int>> rows;
        
        for(int i = 0; i < m; i++) {
            
            sort(mat[i].begin(), mat[i].end());
            auto it = lower_bound(mat[i].begin(), mat[i].end(), 1);
            
            if(it != mat[i].end()){
                int idx = it - mat[i].begin();
                rows.push_back({n-idx, i});
            }
            else{
                rows.push_back({0, i});
            }
        }
        
        sort(rows.begin(), rows.end(), cmp);
        
        vector<int> ans;
        
        for(int i = 0; i < k; i++) {
            ans.push_back(rows[i].second);
        }
        
        return ans;
    }
};

// Solution 2: Binary Search + Max Heap

class Solution {
public:
    int findPower(vector<int>& v, int n) {
        if(v[0] == 0) {
            return 0;
        }
        
        int l = 0, h = n-1;
        int ans;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(v[mid] == 1) {
                ans = mid;
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        return ans + 1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        
        priority_queue<pair<int, int>> pq;
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++) {
            int pow = findPower(mat[i], n);
            pq.push({pow, i});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        
        reverse(ans.begin(), ans.end());      
        return ans;
    }
};