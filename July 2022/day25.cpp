/*
	Find First and Last Position of Element in Sorted Array
	https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

// Solution: Binary Search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1;
        vector<int> ans(2, -1);
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(nums[mid] < target) {
                l = mid+1;
            }
            else if(nums[mid] > target) {
                h = mid-1;
            }
            else {
                if(mid == l || nums[mid] != nums[mid-1]) {
                    ans[0] = mid;
                    break;
                }
                else {
                    ans[0] = mid-1;
                    h = mid-1;
                }
            }
            
        }
        
        h = n-1;
        while(l <= h) {
            int mid = l + (h-l) / 2;
            if(nums[mid] < target) {
                l = mid+1;
            }
            else if(nums[mid] > target) {
                h = mid-1;
            }
            else {
                if(mid == h || nums[mid] != nums[mid+1]) {
                    ans[1] = mid;
                    break;
                }
                else {
                    ans[1] = mid+1;
                    l = mid+1;
                }
            }
        }
        
        return ans;
    }
};