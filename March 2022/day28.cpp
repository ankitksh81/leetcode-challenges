/*
	Search in Rotated Sorted Array II
	https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/

// Solution: Binary Search

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] == target) {
                return true;
            }
            
            if(nums[mid] == nums[l] && nums[mid] == nums[h]) {
                l++;
                h--;
            }
            else if(nums[l] <= nums[mid]) {
                if(target >= nums[l] && target < nums[mid]) {
                    h = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                if(nums[mid] < target && target <= nums[h]) {
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
        }
        return false;
    }
};