/*
	Running Sum of 1d Array
	https://leetcode.com/problems/running-sum-of-1d-array/
*/

// Solution: Prefix Sum

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size());
        result[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            result[i] = nums[i] + result[i-1];
        }
        
        return result;
    }
};