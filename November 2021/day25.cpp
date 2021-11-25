/*
    Maximum subarray
    https://leetcode.com/problems/maximum-subarray/
*/

// Solution: Kadane's algorithm

class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int ans = INT_MIN, curSum = 0;
        for(int a: A) {
            curSum += a;
            ans = max(ans, curSum);
            curSum = max(0, curSum);
        }
        return ans;
    }
};