// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/617/week-5-august-29th-august-31st/3958/


// Solution:

class Solution {
public:
	int findMin(vector<int>& nums) {
		int left = 0, right = nums.size()-1;
		if(!right) {
			return nums[0];
		}

		while(left < right) {
			int mid = left + (right - left) / 2;
			if(nums[left] < nums[right]) {
				return nums[left];
			}
			else if(nums[mid] > nums[right]) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return nums[left];
	}
};