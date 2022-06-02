/*
	Transpose Matrix
	https://leetcode.com/problems/transpose-matrix/
*/

// Solution 1: Directly Copy

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int R = matrix.size(), C = matrix[0].size();
        vector<vector<int>> result(C, vector<int>(R));
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                result[c][r] = matrix[r][c];
            }
        }
        
        return result;
    }
};