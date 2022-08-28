/*
	Sort the Matrix Diagonally
	https://leetcode.com/problems/sort-the-matrix-diagonally/
*/

// Solution 1: Sorting

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


// Solution 2: Min Heap

class Solution {
    void sortDiagonal(int row, int col, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        priority_queue<int, vector<int>, greater<int>> diag;
        
        int len = min(m - row, n - col);
        
        for (int i = 0; i < len; i++) {
            diag.push(mat[row + i][col + i]);
        }
        
        for (int i = 0; i < len; i++) {
            mat[row + i][col + i] = diag.top();
            diag.pop();
        }
    }
    
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        for (int row = 0; row < m; row++) {
            sortDiagonal(row, 0, mat);
        }
        
        for (int col = 0; col < n; col++) {
            sortDiagonal(0, col, mat);
        }
        
        return mat;
    }
};