/*
	Subsets
	https://leetcode.com/problems/subsets/
*/

// Solution: Backtracking

class Solution {
public:
    void getSubsets(vector<int>& nums, int i, vector<int>& curSubset, vector<vector<int>>& result) {
        if(i >= nums.size()) {
            result.push_back(curSubset);
            return;
        }
        
        // include
        curSubset.push_back(nums[i]);
        getSubsets(nums, i+1, curSubset, result);
        curSubset.pop_back();
        
        // not include
        getSubsets(nums, i+1, curSubset, result);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curSubset;
        getSubsets(nums, 0, curSubset, result);
        return result;
    }
};