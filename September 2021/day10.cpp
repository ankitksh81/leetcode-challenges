// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3970/


// Solution:

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long, long>> dp(n);
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long diff = (long)nums[i] - (long)nums[j];
                
                dp[i][diff]++;
                
                if(dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    count += dp[j][diff];
                }
            }
        }
        
        return count;
    }
};
