// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3969/


// Solution 1:

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> mat(n, vector<int>(n, 1));
        
        for(auto it: mines) {
            int x = it[0];
            int y = it[1];
            mat[x][y] = 0;
        }
        
        vector<vector<int>> left, right, top, bottom;
        left = right = top = bottom = mat;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int x = n - i - 1;
                int y = n - j - 1;
                if((i > 0) && top[i][j]) {
                    top[i][j] += top[i - 1][j];
                }
                if((j > 0) && left[i][j]) {
                    left[i][j] += left[i][j-1];
                }
                if((x < n-1) && bottom[x][y]) {
                    bottom[x][y] += bottom[x+1][y];
                }
                if((y < n-1) && right[x][y]) {
                    right[x][y] += right[x][y+1];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, min({left[i][j], right[i][j], top[i][j], bottom[i][j]}));
            }
        }
        
        return ans;
    }
};


// Solution 2:
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int ans=0;
        // just walk from every direction one by one to each cell and store the min 
        //contiguous valid 1's length of every direction
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> mat(n, vector<int>(n, 1));
        
        for(int i = 0; i < mines.size(); i++) {
            mat[mines[i][0]][mines[i][1]] = 0;
        }
        for(int i = 0; i < n; i++) {
             int c = 0;
             for(int j = 0; j < n; j++) {    // walk right to each pos 
                   mat[i][j] ? c++ : c = 0; 
                   dp[i][j] = min(dp[i][j], c);
             }
        }
        for(int i = 0; i < n; i++) {
            int c = 0;
            for(int j = n-1; j >= 0; j--) {   // walk left to each pos
                   mat[i][j] ? c++ : c = 0; 
                   dp[i][j] = min(dp[i][j], c);
            }
        }
        for(int i = 0; i < n; i++) {
            int c = 0;
            for(int j = 0; j < n; j++) {
                  mat[j][i] ? c++ : c = 0;     // walk down to each pos
                  dp[j][i] = min(dp[j][i], c);
            }
        }
        for(int i = 0; i < n; i++) {
            int c = 0;
            for(int j = n-1; j >= 0; j--) {  // walk up to each pos 
                  mat[j][i] ? c++ : c = 0;
                  dp[j][i] = min(c, dp[j][i]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);  
            }
        }
        return ans;
    }
};