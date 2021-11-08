/*
    Unique binary search trees
    https://leetcode.com/problems/unique-binary-search-trees/
*/

// Solution 1: Dynamic programming

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            for(int root = 1; root <= i; root++) {
                dp[i] += dp[root - 1] * dp[i - root];
            }
        }
        
        return dp[n];
    }
};

// Solution 2: Catalan number

class Solution {
public:
    long find_ncr(int n, int r) {
        long ans = 1;
        for(int i = 0; i < r; i++) {
            ans *= n - i;
            ans /= i + 1;
        }
        
        return ans;
    }
    
    int numTrees(int n) {
        return find_ncr(2 * n, n) / (n + 1);
    }
};

// Solution 3: Catalan number

class Solution {
public:
    int numTrees(int n) {
        long ans = 1;
        for(int i = 0; i < n; i++) {
            ans *= (4 * i + 2) / (i + 2.);
        }
        return ans;
    }
};