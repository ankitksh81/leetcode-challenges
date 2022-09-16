/*
        Maximum Score from Performing Multiplication Operations
        https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
*/

// Solution 1: Recursion + Memoization

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int n, int j, vector<int> &nums, vector<int> &multipliers){
        if (j == multipliers.size()) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        
        int left = solve(i + 1, n, j + 1, nums, multipliers) + (nums[i] * multipliers[j]);
        int right = solve(i, n, j + 1, nums, multipliers) + (nums[(n - 1) - (j - i)] * multipliers[j]);
        
        return dp[i][j] = max(left, right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {   
        int n = nums.size(), m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, n, 0, nums, multipliers);
    }
};


// Solution 2: Dynamic Programming

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        int dp[1005];

        for (int i = 1; i <= m; i++) dp[i] = INT_MIN;
        dp[0] = 0;
        
        for (int i = 1; i <= m; i++) {
            // dp[k] -> k rear elements has been used
            int mult = multipliers[i - 1];
            for (int k = i; k >= 0; k--) {
                int nv = INT_MIN;
                if (dp[k] > INT_MIN) {
                    nv = max(nv, dp[k] + nums[i - k - 1] * mult);                                                   
                }
                if (k > 0) {
                    nv = max(nv, dp[k - 1] + nums[n - k] * mult);
                }
                dp[k] = nv;
            }
        }
        
        int ans = dp[0];
        for (int i = 1; i <= m; i++) {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
