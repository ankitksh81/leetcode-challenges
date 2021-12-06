/*
    Minimum cost to move chips to the same position
    https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
*/

// Solution:

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddPos = 0, evenPos = 0;
        for(int x: position) {
            if(x & 1) {
                oddPos++;
            }
            else {
                evenPos++;
            }
        }
        
        return min(oddPos, evenPos);
    }
};