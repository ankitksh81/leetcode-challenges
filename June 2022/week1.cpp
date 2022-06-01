/*
	Minimum Knight Moves
	https://leetcode.com/problems/minimum-knight-moves/
*/

// Solution: HashMap and Solving in only 1 quadrant

class Solution {
    unordered_map<string, int> dp;
public:
    int dfs(int x, int y) {
        string key = to_string(x) + "," + to_string(y);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        if(x + y == 0) {
            return 0;
        }
        else if(x + y == 2) {
            return 2;
        }
        
        int result = min(dfs(abs(x-1), abs(y-2)), dfs(abs(x-2), abs(y-1))) + 1;
        return dp[key] = result;
    }
    
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        
        return dfs(x, y);
    }
};