/*
	Sort the Matrix Diagonally
	https://leetcode.com/problems/sort-the-matrix-diagonally/
*/

// Solution: Sorting

class Solution {
public:
    vector<int> getDiagonal(vector<vector<int>>& mat, int r, int c) {
        vector<int> diag;
        int i = r, j = c;
        while (i < mat.size() && j < mat[0].size()) {
            diag.push_back(mat[i][j]);
            i++;
            j++;
        }
        
        return diag;
    }
    
    void setDiagonal(vector<vector<int>>& mat, vector<int>& diag, int r, int c) {
        int i = 0;
        while (r < mat.size() && c < mat[0].size()) {
            mat[r][c] = diag[i++];
            r++;
            c++;
        }
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int col = n-1; col >= 0; col--) {
            vector<int> diag = getDiagonal(mat, 0, col);
            sort(diag.begin(), diag.end());
            setDiagonal(mat, diag, 0, col);
        }
        
        for (int row = 1; row < m; row++) {
            vector<int> diag = getDiagonal(mat, row, 0);
            sort(diag.begin(), diag.end());
            setDiagonal(mat, diag, row, 0);
        }
        
        return mat;
    }
};