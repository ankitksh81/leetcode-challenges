/*
	K-diff Pairs in an Array
	https://leetcode.com/problems/k-diff-pairs-in-an-array/
*/

// Solution 1: Two Pointers

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, left = 0, right = 1;
        while(left < nums.size() && right < nums.size()) {
            if(left == right || nums[right] - nums[left] < k) {
                right++;
            }
            else if(nums[right] - nums[left] > k) {
                left++;
            }
            else {
                left++;
                cnt++;
                while(left < nums.size() && nums[left] == nums[left-1]) {
                    left++;
                }
            }
        }
        return cnt;
    }
};

// Solution 2: Hashmap