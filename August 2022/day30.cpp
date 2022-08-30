/*
	Rotate Image
	https://leetcode.com/problems/rotate-image/
*/

// Solution: Greedy

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(vector<int> &v: matrix) {
            reverse(v.begin(), v.end());
        }
    }
};