/*
    Best time to buy and sell stock with cooldown
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/

// Solution 1:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev_sold = 0, prev_buy = -prices[0], prev_cd = 0;
        
        for(int i = 1; i < n; i++) {
            int new_sold = 0, new_buy = 0, new_cd = 0;
            if(prev_buy + prices[i] > prev_sold) {
                new_sold = prev_buy + prices[i];
            } else {
                new_sold = prev_sold;
            }
            if(prev_sold > prev_cd) {
                new_cd = prev_sold;
            } else {
                new_cd = prev_cd;
            }
            if(prev_cd - prices[i] > prev_buy) {
                new_buy = prev_cd - prices[i];
            } else {
                new_buy = prev_buy;
            }
            
            prev_sold = new_sold;
            prev_buy = new_buy;
            prev_cd = new_cd;
        }
        
        return prev_sold;
    }
};

// Solution 2:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prev_sold = 0, prev_buy = -prices[0], prev_cd = 0;
        
        for(int i = 1; i < n; i++) {
            int new_sold = max(prev_sold, prev_buy + prices[i]);
            int new_cd = max(prev_cd, prev_sold);
            int new_buy = max(prev_buy, prev_cd - prices[i]);
            
            prev_sold = new_sold;
            prev_buy = new_buy;
            prev_cd = new_cd;
        }
        
        return prev_sold;
    }
};