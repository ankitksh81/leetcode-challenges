/*
	Kth Smallest Element in a Sorted Matrix
	https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
*/

// Solution: Binary Search

class Solution {
public:
    int getCount(vector<vector<int>>& matrix, int val, vector<int> &smallLargePair) {
        int n = matrix.size(), i = n-1, j = 0;
        int cnt = 0;
        
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= val) {
                cnt += (i + 1);
                smallLargePair[0] = max(smallLargePair[0], matrix[i][j]);
                j++;
            }
            else if (matrix[i][j] > val) {
                smallLargePair[1] = min(smallLargePair[1], matrix[i][j]);
                i--;
            }
        }
        
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], h = matrix[n-1][n-1];
        
        while (l < h) {
            int mid = l + (h - l) / 2;
            vector<int> smallLargePair = {matrix[0][0], matrix[n-1][n-1]};
            int cnt = getCount(matrix, mid, smallLargePair);
            
            if (cnt == k) {
                return smallLargePair[0];
            }
            if (cnt < k) {
                l = smallLargePair[1];
            }
            else {
                h = smallLargePair[0];
            }
        }
        
        return l;
    }
};