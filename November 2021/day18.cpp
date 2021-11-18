/*
    Find all numbers disappeared in an array
    https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/

// Solution 1: Extra space

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int x: nums) {
            m[x]++;
        }
        
        vector<int> ans;
        for(int i = 1; i <= nums.size(); i++) {
            if(m[i] == 0) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

// Solution 2: Constant space

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= n) {
                ans.push_back(i+1);
            }
        }
        
        return ans;
    }
};