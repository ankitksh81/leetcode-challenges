// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3986/


// Solution 1:

class Solution {
public:
    int tribonacci(int n) {
        int dp[38];
        dp[0] = 0, dp[1] = 1, dp[2] = 1;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};


// Solution 2:

class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1;
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        
        int current = 2, count = 2;
        
        while(count < n) {
            current = first + second + third;
            first = second;
            second = third;
            third = current;
            count++;
        }
        
        return third;
    }
};