/*
    Burst Balloons
    https://leetcode.com/problems/burst-balloons/
*/

// Solution 1: Top-Down DP

class Solution {
    int dp[505][505];
public:
    int findMaxCoins(vector<int> &nums, int l, int r) {
        if(r - l < 0) {
            return 0;
        }
        
        if(dp[l][r] != -1) {
            return dp[l][r];
        }
        
        int res = 0;
        for(int i = l; i <= r; i++) {
            int gain = nums[l-1] * nums[i] * nums[r+1];
            int remaining = findMaxCoins(nums, l, i-1) + findMaxCoins(nums, i+1, r);
            res = max(res, remaining + gain);
        }
        
        return dp[l][r] = res;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        
        memset(dp, -1, sizeof(dp));
        return findMaxCoins(nums, 1, nums.size()-2);
    }
};

// Solution 2: Bottom-Up DP

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        
        int dp[nums.size()][nums.size()];
        memset(dp, 0, sizeof(dp));
        
        for(int l = nums.size() - 2; l >= 1; l--) {
            for(int r = l; r <= nums.size() - 2; r++) {
                for(int i = l; i <= r; i++) {
                    int gain = nums[l - 1] * nums[i] * nums[r + 1];
                    int remaining = dp[l][i-1] + dp[i+1][r];
                    dp[l][r] = max(dp[l][r], remaining + gain);
                }
            }
        }
        
        return dp[1][nums.size()-2];
    }
};