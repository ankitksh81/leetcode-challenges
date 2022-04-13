/*
	Spiral Matrix II
	https://leetcode.com/problems/spiral-matrix-ii/
*/

// Solution 1: Spiral Traversal

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, bottom = n-1, left = 0, right = n-1;
        vector<vector<int>> ans(n, vector<int>(n));
        
        int val = 1;
        while(top <= bottom && left <= right) {
            if(top == bottom && left == right) {
                ans[top][left] = val;
                break;
            }
            
            int tptr = top, bptr = bottom, lptr = left, rptr = right;
            // left->right
            while(lptr < right) {
                ans[top][lptr++] = val++;
            }
            // top->bottom
            while(tptr < bottom) {
                ans[tptr++][right] = val++;
            }
            // right->left
            while(rptr > left) {
                ans[bottom][rptr--] = val++;
            }
            // bottom->top
            while(bptr > top) {
                ans[bptr--][left] = val++;
            }
            
            // change values
            top++;
            right--;
            bottom--;
            left++;
        }
        
        return ans;
    }
};

// Solution 2: Optimized Spiral Traversal

class Solution {
public:

    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
       int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n) {
            result[row][col] = cnt++;
            int r = floorMod(row + dir[d][0], n);
            int c = floorMod(col + dir[d][1], n);
            // change direction if next cell is non zero
            if (result[r][c] != 0) d = (d + 1) % 4;
            row += dir[d][0];
            col += dir[d][1];
        }
        return result;
    }
};