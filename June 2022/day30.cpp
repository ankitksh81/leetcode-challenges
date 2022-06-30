/*
	Minimum Moves to Equal Array Elements II
	https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
*/

// Solution: Sorting

class Solution {
    long findMinSteps(vector<int>& nums, int val) {
        long res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res += abs(nums[i] - val);
        }
        
        return res;
    }
    
public:
    int minMoves2(vector<int>& nums) {
        int N = nums.size();
        if (N == 2) return abs(nums[0] - nums[1]);
        sort(nums.begin(), nums.end());
        if (N & 1) {
            N = N / 2;
            return (int)findMinSteps(nums, nums[N]);
        }
        return (int)min(findMinSteps(nums, nums[N/2]), findMinSteps(nums, nums[N/2 + 1]));
    }
};