/*
	Wiggle Subsequence
	https://leetcode.com/problems/wiggle-subsequence/
*/

// Solution 1: 1D - Dynamic Programming

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        int up = 1, down = 1;
        
        for (int i = 1; i < N; i++) {
            if (nums[i] - nums[i-1] > 0) {
                up = down + 1;
                down = down;
            }
            else if (nums[i] - nums[i-1] == 0) {
                up = up;
                down = down;
            }
            else {
                down = up + 1;
                up = up;
            }
        }
        
        return max(up, down);
    }
};


// Solution 2: Greedy

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int N = nums.size();
        if (N < 2)  return N;
        
        int prevDiff = nums[1] - nums[0];
        int count = prevDiff != 0 ? 2 : 1;
        
        for (int i = 2; i < N; i++) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
                count++;
                prevDiff = diff;
            }
        }
        
        return count;
    }
};