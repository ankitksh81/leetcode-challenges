/*
	Richest Customer Wealth
	https://leetcode.com/problems/richest-customer-wealth/
*/

// Solution:

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        for(int i = 0; i < accounts.size(); i++) {
            int curWealth = 0;
            for(int j = 0; j < accounts[i].size(); j++) {
                curWealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, curWealth);
        }
        
        return maxWealth;
    }
};