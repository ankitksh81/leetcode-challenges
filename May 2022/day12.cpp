/*
	Permutations II
	https://leetcode.com/problems/permutations-ii/
*/

// Solution: Backtracking

class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int> nums, int i, int j) {
        if (i == j) {
            ans.push_back(nums);
            return;
        }
        
        for (int k = i; k <= j; k++) {
            if (i != k && nums[i] == nums[k]) {
                continue;
            }
            swap(nums[i], nums[k]);
            solve(nums, i+1, j);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        solve(nums, 0, n-1);
        return ans;
    }
};