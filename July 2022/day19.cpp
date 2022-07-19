/*
	Pascal's Triangle
	https://leetcode.com/problems/pascals-triangle/
*/

// Solution 1: 2D Dynamic Programming

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++) {
            vector<int> v = vector<int>(i+1);
            v[0] = v[i] = 1;
            res.push_back(v);
        }
        
        if(numRows <= 2) {
            return res;
        }
        
        for(int row = 2; row < numRows; row++) {
            for(int i = 1; i < res[row].size()-1; i++) {
                res[row][i] = res[row-1][i-1] + res[row-1][i];
            }
        }
        
        return res;
    }
};