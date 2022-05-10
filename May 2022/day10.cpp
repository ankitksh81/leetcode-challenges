/*
	Combination Sum III
	https://leetcode.com/problems/combination-sum-iii/
*/

// Solution: Backtracking

class Solution {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> result;
    set<vector<int>> vis;
public:
    void solve(int k, int target, int sum, int idx, vector<int> res) {
        if(sum > target) {
            return;
        }
        
        if(sum == target && k == 0) {
            result.push_back(res);
            return;
        }
        
        for(int i = idx; i < nums.size(); i++) {
            res.push_back(nums[i]);
            solve(k-1, target, sum + nums[i], i + 1, res);
            res.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        solve(k, n, 0, 0, res);
        return result;
    }
};