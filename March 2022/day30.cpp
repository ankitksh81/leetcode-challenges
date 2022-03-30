/*
	Search a 2D Matrix
	https://leetcode.com/problems/search-a-2d-matrix/
*/

// Solution:

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n-1;
        while(r < m && c >= 0) {
            if(matrix[r][c] > target) {
                c--;
            }
            else if(matrix[r][c] < target) {
                r++;
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};