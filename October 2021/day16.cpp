/*
    Best time to buy and sell stock III
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/

// Solution:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dpl(n), dpr(n);
        int mxProfit = 0, mn = prices[0], mx = prices[n-1];
        dpl[0] = 0;
        
        for(int i = 1; i < n; i++) {
            mn = min(mn, prices[i]);
            mxProfit = max(mxProfit, prices[i] - mn);
            dpl[i] = max(dpl[i-1], mxProfit);
        }
        dpr[n-1] = 0, mxProfit = 0;
        for(int i = n-2; i >= 0; i--) {
            mx = max(mx, prices[i]);
            mxProfit = max(mxProfit, mx - prices[i]);
            dpr[i] = max(dpr[i+1], mxProfit);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(dpl[i] + dpr[i], ans);
        }
        return ans;
    }
};