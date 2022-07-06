/*
	Fibonacci Number
	https://leetcode.com/problems/fibonacci-number/
*/

// Solution 1: Recursion

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2)   return 1;
        return fib(n-1) + fib(n-2);
    }
};


// Solution 2: Memoization

class Solution {
    int dp[31];
public:
    int solve(int n) {
        if (n == 1 || n == 2)   return 1;
        if (dp[n] != -1)    return dp[n];
        
        return dp[n] = solve(n-1) + solve(n-2);
    }
    
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2)   return 1;
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};


// Solution 3: Dynamic Programming

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};


// Solution 4: Constant Space Dynamic Programming

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int num1 = 1, int num2 = 1;
        
        int cur;
        for (int i = 3; i <= n; i++) {
            cur = num1 + num2;
            num1 = num2;
            num2 = cur;
        }
        
        return cur;
    }
};