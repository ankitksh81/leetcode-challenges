/*
	Minimum Operations to Reduce X to Zero
	https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
*/

// Solution: Two Pointers

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int cur = 0;
        for (int num : nums) {
            cur += num;
        }
        
        int res = INT_MAX;
        int l = 0;
        
        for (int r = 0; r < n; r++) {
            cur -= nums[r];
            while (cur < x && l <= r) {
                cur += nums[l];
                l += 1;
            }
            
            if (cur == x) {
                res = min(res, (n - 1 - r) + l);
            }
        }
        
        return res != INT_MAX ? res : -1;
    }
};