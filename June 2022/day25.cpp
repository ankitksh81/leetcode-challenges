/*
	Non-decreasing Array
	https://leetcode.com/problems/non-decreasing-array/
*/

// Solution: Greedy

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int N = nums.size(), inv = 0;
        
        for (int i = 1; i < N; i++) {
            if (nums[i] < nums[i-1]) {
                if (inv == 1) {
                    return false;
                }
                
                inv++;
                
                if (i < 2 || nums[i-2] <= nums[i]) {
                    nums[i-1] == nums[i];
                }
                else {
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};