/*
    Partition equal subset sum
    https://leetcode.com/problems/partition-equal-subset-sum/
*/

// Solution 1: Bottom-Up DP

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) {
            return false;
        }
        
        int n = nums.size();
        int target = sum / 2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1));
        
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                if(i == 0) {
                    dp[i][j] = false;
                }
                if(j == 0) {
                    dp[i][j] = true;
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
    }
};

// Solution 2: Dp with bitmask

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<100 * 200> bs(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum & 1) {
            return false;
        }
        
        for(auto num : nums) {
            bs |= bs << num;
        }
        
        return bs[sum / 2];
    }
};