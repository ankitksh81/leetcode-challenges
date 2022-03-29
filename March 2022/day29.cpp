/*
	Find the Duplicate Number
	https://leetcode.com/problems/find-the-duplicate-number/
*/

// Solution 1: Negative Marking

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup = -1;
        for(int i = 0; i < nums.size(); i++) {
            int cur = abs(nums[i]);
            if(nums[cur] < 0) {
                dup = cur;
                break;
            }
            nums[cur] *= -1;
        }
        
        return dup;
    }
};