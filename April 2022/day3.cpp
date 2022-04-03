/*
	Next Permutation
	https://leetcode.com/problems/next-permutation/
*/

// Solution 1: Using inbuit function

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// Solution 2: Single Pass

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = n-2;
        while(idx >= 0) {
            if(nums[idx] < nums[idx+1]) {
                break;
            }
            idx--;
        }
        
        if(idx < 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            int j;
            for(j = n-1; j >= 0; j--) {
                if(nums[j] > nums[idx]) {
                    break;
                }
            }
            swap(nums[j], nums[idx]);
            reverse(nums.begin() + idx + 1, nums.end());
        }
    }
};