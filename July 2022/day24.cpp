/*
	Search a 2D Matrix II
	https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

// Solution: Two Pointers (Search space reduction)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size()-1;
        
        while (i < matrix.size() && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                i++;
            }
            else if (matrix[i][j] > target) {
                j--;
            }
        }
        
        return false;
    }
};