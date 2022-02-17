/*
	Combination Sum
	https://leetcode.com/problems/combination-sum/
*/

// Solution: Backtracking

class Solution {
    vector<vector<int>> result;
public:
    void solve(vector<int>& candidates, int target, int i, int j, vector<int>& temp) {
        if(i >= j) {
            if(target == 0) {
                result.push_back(temp);
            }
            return;
        }
        
        if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, j, temp);
            temp.pop_back();
        }
        solve(candidates, target, i+1, j, temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, target, 0, candidates.size(), temp);
        return result;
    }
};