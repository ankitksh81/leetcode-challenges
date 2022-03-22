/*
	Sparse Matrix Multiplication
	https://leetcode.com/problems/sparse-matrix-multiplication/
*/

// Solution 1: Optimized Brute Force

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int k = mat1[0].size();
        int m = mat2[0].size();
        
        vector<vector<int>> ans(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                if(mat1[i][j] != 0) {
                    for(int c = 0; c < m; c++) {
                        ans[i][c] += mat1[i][j] * mat2[j][c];
                    }
                }
            }
        }
        
        return ans;
    }
};

// Solution 2: List of List

class Solution {
public:
    vector<vector<pair<int, int>>> compressMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<vector<pair<int, int>>> compressedMatrix(r);
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] != 0) {
                    compressedMatrix[i].push_back({matrix[i][j], j});
                }
            }
        }
        
        return compressedMatrix;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        
        vector<vector<pair<int, int>>> A = compressMatrix(mat1);
        vector<vector<pair<int, int>>> B = compressMatrix(mat2);
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for(int mat1row = 0; mat1row < m; mat1row++) {
            for(auto [element1, mat1col] : A[mat1row]) {
                for(auto [element2, mat2col] : B[mat1col]) {
                    ans[mat1row][mat2col] += element1 * element2;
                }
            }
        }
        
        return ans;
    }
};