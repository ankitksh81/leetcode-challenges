/*
	Maximum Erasure Value
	https://leetcode.com/problems/maximum-erasure-value/
*/

// Solution: Sliding Window & HashMap

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int l = 0, r = 0;
        unordered_map<int, int> freq;
        int sum = 0;
        
        while (r < n) {
            sum += nums[r];
            freq[nums[r]]++;
            while (l < r && freq[nums[r]] > 1) {
                sum -= nums[l];
                freq[nums[l]]--;
                l++;
            }
            
            result = max(result, sum);
            r++;
        }
        
        return result;
    }
};