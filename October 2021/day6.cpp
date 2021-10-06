/*
    Find all duplicates in an array
    https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/

// Solution:

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int num: nums) {
            if(nums[abs(num) - 1] < 0) {
                ans.push_back(abs(num));
            }
            else {
                nums[abs(num) - 1] = -nums[abs(num) - 1];
            }
        }
        
        return ans;
    }
};