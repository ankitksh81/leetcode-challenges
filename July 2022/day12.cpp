/*
	Matchsticks to Square
	https://leetcode.com/problems/matchsticks-to-square/
*/

// Solution 1: Backtracking

class Solution {
    bool dp[16];
    bool solve(vector<int>& arr, int curSum, int& target, int sides, int idx, int& n) {
        if (sides == 0) return true;
        
        if (curSum > target) return false;
        
        if (curSum == target) {
            return solve(arr, 0, target, sides - 1, 0, n);
        }
        
        for (int i = idx; i < n; i++) {
            if (!dp[i]) {
                dp[i] = true;
                curSum += arr[i];
                
                if (solve(arr, curSum, target, sides, i + 1, n)) return true;
                
                curSum -= arr[i];
                dp[i] = false;
            }
        }
        
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum%4 != 0) return false;
        
        memset(dp, false, sizeof(dp));
        
        int target = sum/4;
        
        return solve(matchsticks, 0, target, 3, 0, n);
    }
};


// Solution 2: Dynamic Programming with BitMasking

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int N = matchsticks.size();
        int sum = accumulate(begin(matchsticks), end(matchsticks), 0);
        if (sum % 4 != 0 || N < 4) return false;
        
        sum /= 4;
        vector<int> subsetSum((1 << N), -1);
        subsetSum[0] = 0;
        
        for (int mask = 0; mask < (1 << N); mask++) {
            if (subsetSum[mask] == -1) continue;
            
            for (int i = 0; i < N; i++) {
                if (!(mask & (1 << i)) && subsetSum[mask] + matchsticks[i] <= sum) {
                    subsetSum[mask | (1 << i)] = (subsetSum[mask] + matchsticks[i]) % sum;
                }
            }
            
            if (subsetSum[(1 << N) - 1] == 0) {
                return true;
            }
        }
        
        return subsetSum[(1 << N) - 1] == 0;
    }
};