/*
	Longest Increasing Path in a Matrix
	https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

// Solution 1: Recursion

class Solution {
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int findLongestIncPath(vector<vector<int>>& matrix, int i, int j, int prev) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() ||
        matrix[i][j] <= prev) {
            return 0;
        }

        int result = 0;
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            result = max(result, findLongestIncPath(matrix, x, y, matrix[i][j]));
        }

        return result + 1;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, findLongestIncPath(matrix, i, j, -1));
            }
        }

        return result;
    }
};

// Solution 2: Recursion with Memoization

class Solution {
    int dp[200][200];
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int findLongestIncPath(vector<vector<int>>& matrix, int i, int j, int prev) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() ||
        matrix[i][j] <= prev) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int result = 0;
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            result = max(result, findLongestIncPath(matrix, x, y, matrix[i][j]));
        }

        return dp[i][j] = result + 1;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        memset(dp, -1, sizeof(dp));

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, findLongestIncPath(matrix, i, j, -1));
            }
        }

        return result;
    }
};