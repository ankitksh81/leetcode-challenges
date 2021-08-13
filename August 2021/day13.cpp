// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3888/


// Solutioin 1:

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<int> rows, cols;

        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++) {
        		if(matrix[i][j] == 0) {
        			rows.insert(i);
        			cols.insert(j);
        		}
        	}
        }

        for(int i = 0; i < m; i++) {
        	for(int j = 0; j < n; j++){
        		if(rows.count(i) || cols.count(j)) {
        			matrix[i][j] = 0;
        		}
        	}
        }
    }
};


// Solution 2:

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row_zero = false, col_zero = false;

        for(int i = 0; i < n; i++) {
        	if(matrix[0][i] == 0) {
        		row_zero = true;
        		break;
        	}
        }
        for(int i = 0; i < m; i++) {
        	if(matrix[i][0] == 0) {
        		col_zero = true;
        		break;
        	}
        }
        for(int i = 1; i < m; i++) {
        	for(int j = 1; j < n; j++) {
        		if(matrix[i][j] == 0) {
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }
        for(int i = 1; i < m; i++) {
        	for(int j = 1; j < n; j++) {
        		if(matrix[i][0] == 0 || matrix[0][j] == 0) {
        			matrix[i][j] = 0;
        		}
        	}
        }

        if(row_zero) {
        	for(int i = 0; i < n; i++) {
        		matrix[0][i] = 0;
        	}
        }
        if(col_zero) {
        	for(int i = 0; i < m; i++) {
        		matrix[i][0] = 0;
        	}
        }
    }
};