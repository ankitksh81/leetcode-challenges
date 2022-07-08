/*
	Paint House III
	https://leetcode.com/problems/paint-house-iii/
*/

// Solution 1: Recursion + Memoization

class Solution {
public:
    int memo[100][100][21];
    const int MAX_COST = 1000001;
    
    int findMinCost(vector<int>& houses, vector<vector<int>>& cost, int targetCount, int currIndex, int neighborhoodCount, int prevHouseColor) {
        if (currIndex == houses.size()) {
            return neighborhoodCount == targetCount ? 0 : MAX_COST;
        }
        
        if (neighborhoodCount > targetCount) {
            return MAX_COST;
        }
        
        if (memo[currIndex][neighborhoodCount][prevHouseColor] != -1) {
            return memo[currIndex][neighborhoodCount][prevHouseColor];
        }
        
        int minCost = MAX_COST;
        if (houses[currIndex]) {
            int newNeighborhoodCount = neighborhoodCount + (houses[currIndex] != prevHouseColor);
            minCost = 
                findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, houses[currIndex]);
        } else {
            int totalColors = cost[0].size();
            
            for (int color = 1; color <= totalColors; color++) {
                int newNeighborhoodCount = neighborhoodCount + (color != prevHouseColor);
                int currCost = cost[currIndex][color - 1]
                    + findMinCost(houses, cost, targetCount, currIndex + 1, newNeighborhoodCount, color);
                minCost = min(minCost, currCost);
            }
        }
        
        return memo[currIndex][neighborhoodCount][prevHouseColor] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(memo, -1, sizeof(memo));
        int answer = findMinCost(houses, cost, target, 0, 0, 0);
        
        return answer == MAX_COST ? -1 : answer;
    }
};


// Solution 2: Dynamic Programming

class Solution {
public:
    const int MAX_COST = 1000001;

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(target + 1, vector<int>(n, MAX_COST)));
        
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) {
                memo[0][1][color - 1] = 0;
            } else if (!houses[0]) {
                memo[0][1][color - 1] = cost[0][color - 1];
            }
        }
        
        for (int house = 1; house < m; house++) {
            for (int neighborhoods = 1; neighborhoods <= min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    if (houses[house] && color != houses[house]) {
                        continue;
                    }
 
                    int currCost = MAX_COST;
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            currCost = min(currCost, memo[house - 1][neighborhoods - 1][prevColor - 1]);
                        } else {
                            currCost = min(currCost, memo[house - 1][neighborhoods][color - 1]);
                        }
                    }
                    
                    int costToPaint = houses[house] ? 0 : cost[house][color - 1];
                    memo[house][neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
        }
        
        int minCost = MAX_COST;
        for (int color = 1; color <= n; color++) {
            minCost = min(minCost, memo[m - 1][target][color - 1]);
        }
        
        return minCost == MAX_COST ? -1 : minCost;
    }
};