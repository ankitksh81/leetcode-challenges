/*
    Maximal Rectangle
    https://leetcode.com/problems/maximal-rectangle/
*/

// Solution 1: Brute Force

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        
        int maxArea = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = j == 0 ? 1 : dp[i][j-1] + 1;
                    
                    int width = dp[i][j];
                    
                    for(int k = i; k >= 0; k--) {
                        width = min(width, dp[k][j]);
                        maxArea = max(maxArea, width * (i - k + 1));
                    }
                 }
            }
        }
        
        return maxArea;
    }
};

// Solution 2: Stack

class Solution {
public:
    int findMaxArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(!st.empty()) {
                    width = i - st.top() - 1;
                }
                else {
                    width = i;
                }
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        int maxArea = 0;
        vector<int> dp(matrix[0].size());
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                dp[j] = matrix[i][j] == '1' ? dp[j] + 1 : 0; 
            }
            maxArea = max(maxArea, findMaxArea(dp));
        }
        
        return maxArea;
    }
};

// Solution 3: DP

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        
        vector<int> left(n), right(n, n), height(n);
        int maxArea = 0;
        for(int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    height[j]++;
                }
                else {
                    height[j] = 0;
                }
            }
            
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                }
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            
            for(int j = n-1; j >= 0; j--) {
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                }
                else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            
            for(int j = 0; j < n; j++) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        
        return maxArea;
    }
};