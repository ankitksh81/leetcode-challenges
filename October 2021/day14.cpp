/*
    Perfect Squares
    https://leetcode.com/problems/perfect-squares/
*/

// Solution 1:

class Solution {
    int dp[10005];
public:
    int solve(int n) {
        if(n == 0) {
            return 0;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++) {
            ans = min(ans, 1 + solve(n - i*i));
        }
        return dp[n] = ans;
    }
    
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        return solve(n);
    }
};

// Solution 2:

class Solution {
public:
    bool isPs(int n) {
        int a = sqrt(n);
        return a*a == n;
    }
    
    int numSquares(int n) {
        if(isPs(n)) {
            return 1;
        }
        vector<int> dp(n+1);
        for(int i = 1; i <= n; i++) {
            dp[i] = i;
            for(int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
        return dp[n];
    }
};

// Solution 3:

/*
    legendre's 3-square theorem
    A number can be represented as sum of 3 perfect squares if
    it is not of the form 4^a(8b + 7)
    1. If perfect square, ans = 1
    2. If in the above form, ans = 4
    3. If it can be divided in 2 parts such that both parts are perfect square, ans = 2
    4. If none of the above cases, ans = 3
*/

class Solution {
public:
    bool isPs(int n) {
        int a = sqrt(n);
        return a*a == n;
    }
    
    int numSquares(int n) {
        if(isPs(n)) {
            return 1;
        }
        
        while(n % 4 == 0) {
            n /= 4;
        }
        if(n % 8 == 7) {
            return 4;
        }
        
        for(int i = 1; i*i <= n; i++) {
            int b = sqrt(n - i*i);
            if(b * b == (n - i*i)) {
                return 2;
            }
        }
        return 3;
    }
};