/*
	Remove Duplicates from Sorted Array II
	https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/

// Solution: Overwriting Duplicates

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1, cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] ==nums[i-1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }
            if(cnt <= 2) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};