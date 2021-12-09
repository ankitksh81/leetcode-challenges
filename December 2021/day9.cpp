/*
    Jump Game III
    https://leetcode.com/problems/jump-game-iii/
*/

// Solution:

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(arr[start] == 0) {
            return true;
        }
        vector<bool> vis(n, false);
        queue<int> q;
        vis[start] = true;
        q.push(start);
        
        while(!q.empty()) {
            auto idx = q.front();
            q.pop();
            if(arr[idx] == 0) {
                return true;
            }
            
            int right_idx = idx + arr[idx];
            int left_idx = idx - arr[idx];
            if(right_idx < n && !vis[right_idx]) {
                vis[right_idx] = true;
                q.push(idx + arr[idx]);
            }
            if(left_idx >= 0 && !vis[left_idx]) {
                vis[left_idx] = true;
                q.push(idx - arr[idx]);
            }
        }
        
        return false;
    }
};