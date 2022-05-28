/*
	Missing Number
	https://leetcode.com/problems/missing-number/
*/

// Solution 1: Using maths

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long sum = n * (n+1) / 2;
        long res = accumulate(nums.begin(), nums.end(), 0);
        
        return (sum - res);
    }
};

// Solution 2: Xor

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x ^= i;
            x ^= nums[i];
        }
        
        return x ^ nums.size();
    }
};