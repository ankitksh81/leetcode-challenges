// Problem Link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3977/


// Solution 1:

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int top = 0, left = 0, right = n-1, down = m-1;
        
        while(true) {
            // left to right
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            if(++top > down) {
                return ans;
            }

            // top to bottom
            for(int i = top; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            if(--right < left) {
                return ans;
            }

            // right to left
            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[down][i]);
            }
            if(--down < top) {
                return ans;
            }

            // bottom to top
            for(int i = down; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            if(++left > right) {
                return ans;
            }
        }

        return ans;
    }
};


// Solution 2:

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 && matrix[0].size() == 0) {
            return {};
        }
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = 0, top = 0, left = 0, right = n-1, bottom = m-1;

        vector<int> ans;
        while(top <= bottom && left <= right) {
            col = left;
            while(col <= right) {
                ans.push_back(matrix[top][col]);
                col++;
            }
            top++;

            row = top;
            while(row <= bottom) {
                ans.push_back(matrix[row][right]);
                row++;
            }
            right--;

            // corner case: only 1 row left
            if(top <= bottom) {
                col = right;
                while(col >= left) {
                    ans.push_back(matrix[bottom][col]);
                    col--;
                }
                bottom--;
            }

            // corner case: only 1 column left
            if(left <= right) {
                row = bottom;
                while(row >= top) {
                    ans.push_back(matrix[row][left]);
                    row--;
                }
                left++;
            }
        }

        return ans;
    }
};