/*
	Longest Increasing Subsequence
	https://leetcode.com/problems/longest-increasing-subsequence/
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        int result = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[prev] < nums[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                    result = max(dp[i], result);
                }
            }
        }
        
        return result;
    }
};


// Solution 2: Dynamic Programming + Binary Search

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i = 1; i < n; i++) {
            if(v.back() < nums[i]) {
                v.push_back(nums[i]);
                continue;
            }
            
            int l = 0, h = v.size()-1;
            while(l < h) {
                int mid = l + (h - l) / 2;
                if(v[mid] >= nums[i]) {
                    h = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            
            v[l] = nums[i];
        }
        
        return v.size();
    }
};