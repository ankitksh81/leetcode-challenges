// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3837/


// Solution 1:

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {{}};
        
        int size = 0, start = 0;
        
        for(int i = 0; i < nums.size(); i++){
            start = i >= 1 && nums[i] == nums[i-1] ? size : 0;
            size = ans.size();
            
            for(int j = start; j < size; j++) {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};


// Solution 2:

class Solution {
    public:
    void findsubset(vector<int> &nums, int ind, vector<vector<int>> &ans, vector<int> &ds) {
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[i-1])
                continue;
            ds.push_back(nums[i]);
            findsubset(nums, i+1, ans, ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findsubset(nums, 0, ans, ds);
        return ans;
    }
};