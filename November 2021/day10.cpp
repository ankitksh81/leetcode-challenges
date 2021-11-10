/*
    Best time to buy and sell stock II
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

// Solution:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int ans = 0;
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                ans += prices[i] - prices[i-1];
            }
        }
        return ans;
    }
};