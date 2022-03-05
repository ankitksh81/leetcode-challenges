/*
	Delete and Earn
	https://leetcode.com/problems/delete-and-earn/
*/

// Solution: Dynamic Programming

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int size = 10001;
        vector<int> cnt(size), dp(size);
        for (int num : nums) {
            cnt[num] += num;
        }
        
        dp[1] =  cnt[1];
        
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + cnt[i]);
        }
        
        return dp[size-1];
    }
};