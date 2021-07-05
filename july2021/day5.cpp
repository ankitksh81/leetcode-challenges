/* Day 5
    Question link:
*/

// Solution 1

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size():
        
        if(m * n != r * c) {
            return mat;
        }

        vector<vector<int>> res(r, vector<int>(c));
        for(int i = 0; i < total; i++) {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        return res;
    }
};

// Solution 2

class Soultion {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size():

        if(m * n != r * c) {
            return mat;
        }

        vector<vector<int>> res(r, vector<int>(c));
        int l = 0, h = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                int a = mat[i][j];
                res[l][h] = a;

                h++;
                if(h == c) {
                    l++;
                    h = 0;
                }
            }
        }
        return res;
    }
};
