/*
    Longest common subsequence
    https://leetcode.com/problems/longest-common-subsequence/
*/

// Solution 1:

int dp[1001][1001];
class Solution {
public:
    int func(int i, int j, string &text1, string &text2){
        if(i < 0 || j < 0){
            return 0;
        }
        else if(dp[i][j] != -1){
            return dp[i][j];
        }
        else if(text1[i] == text2[j]){
            return dp[i][j] = 1 + func(i-1, j-1, text1, text2);
        }
        else
            return dp[i][j] = max(func(i-1, j, text1, text2), func(i, j-1, text1, text2));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        for(int i = 0 ; i < 1001; i++){
            for(int j = 0; j < 1001; j++){
                dp[i][j] = -1;
            }
        }
        int n = text1.length(), m = text2.length();
        return func(n-1, m-1, text1, text2);
    }
};


// Solution 2:

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int ans[m + 1][n + 1];
        
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    ans[i][j] = 0;
                }
                else if(text1[i - 1] == text2[j - 1]) {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                }
                else {
                    ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
                }
            }
        }
        
        return ans[m][n];
    }
};