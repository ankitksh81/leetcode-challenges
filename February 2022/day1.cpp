/*
	Best Time to Buy and Sell Stock
	https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

// Solution: One Pass

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0, min_cost = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            max_profit = max(max_profit, prices[i] - min_cost);
            min_cost = min(min_cost, prices[i]);
        }
        
        return max_profit;
    }
};