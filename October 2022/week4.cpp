/*
	Best Meeting Point
	https://leetcode.com/problems/best-meeting-point/description/
*/

// Solution 1: Sorting

class Solution {
public:
    int calDist(vector<int> &points, int origin) {
        int dist = 0;
        for (int point : points) {
            dist += abs(point - origin);
        }

        return dist;
    }

    int minTotalDistance(vector<vector<int>>& grid) {
        const int M = grid.size(), N = grid[0].size();
        vector<int> rows, cols;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        int row = rows[rows.size() / 2];
        sort(cols.begin(), cols.end());
        int col = cols[cols.size() / 2];
        
        return calDist(rows, row) + calDist(cols, col);
    }
};


// Solution 2: Collecting coordinates in sorted order

class Solution {
public:
    int calDist(vector<int> &points) {
        int dist = 0;
        int l = 0, r = points.size()-1;

        while (l < r) {
            dist += points[r] - points[l];
            l++;
            r--;
        }

        return dist;
    }

    vector<int> collectCols(vector<vector<int>>& grid) {
        vector<int> cols;
        for (int i = 0; i < grid[0].size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][i] == 1) {
                    cols.push_back(i);
                }
            }
        }
        return cols;
    }

    vector<int> collectRows(vector<vector<int>>& grid) {
        vector<int> rows;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                }
            }
        }

        return rows;
    }

    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows = collectRows(grid);
        vector<int> cols = collectCols(grid);
        
        return calDist(rows) + calDist(cols);
    }
};