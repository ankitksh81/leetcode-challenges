/*
	Number of Submatrices That Sum to Target
	https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
*/

// Solution: 2D Prefix Sum (Horizontal 1D Prefix Sum)

class Solution {
public:
    int getNumSubmatrixSumTarget(vector<vector<int>>& pref, int target, int r1, int r2) {
        int R = pref.size()-1, C = pref[0].size()-1;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int curSum = 0, cnt = 0;
        
        for (int c = 1; c <= C; c++) {
            curSum = pref[r2][c] - pref[r1-1][c];
            if (mp.find(curSum - target) != mp.end()) {
                cnt += mp[curSum - target];
            }
            mp[curSum]++;
        }
        
        return cnt;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        vector<vector<int>> pref(M + 1, vector<int>(N + 1));
        
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        unordered_map<int, int> mp;
        int result = 0;
        for (int r1 = 1; r1 <= M; r1++) {
            for (int r2 = r1; r2 <= M; r2++) {
                result += getNumSubmatrixSumTarget(pref, target, r1, r2);
            }
        }
        
        return result;
    }
};