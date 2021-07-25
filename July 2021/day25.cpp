/* Day 25
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3826/
*/

// Solution 1:

class Solution {
public:
    int findIntegers(int n) {
        n++;
        int odd[34] = {};
        int num = n;
        for(int i = 0; i < 32; i++){
            odd[i] = num % 2;
            num /= 2;
        }

        int ans = 0;
        int dp[34] = {};
        dp[0] = 1;
        dp[1] = 2;

        for(int i = 2; i < 32; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        for(int i = 31; i >= 0; i--){
            if(odd[i]){
                ans += dp[i];
            }
            if(odd[i] and odd[i+1]){
                break;
            }
        }
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    int findIntegers(int n) {
        vector<int>dp(32);
        dp[0] = 1;
        dp[1] = 2;

        for(int i = 2; i <= 31; i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        int shift = 31, prebit = 0, ans = 0;
        while(shift >= 0) {
            //whether the first bit is 1
            if(n & (1 << shift)) {
                ans += dp[shift];
                if(prebit)
                    return ans;
                prebit = 1;
            }
            else prebit = 0;
            shift--;
        }
        return ans+1;

    }
};
