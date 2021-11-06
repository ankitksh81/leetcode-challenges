/*
    Single Number III
    https://leetcode.com/problems/single-number-iii/
*/

// Solution: Bit Manipulation

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        int i, x = 0, y = 0;
        long long xor1;
        xor1 = nums[0];
        // Get xor of all array  elements
        for(int i = 1; i < n; i++) {
            xor1 ^= nums[i];
        }
        
        // Get rightmost set bit
        long long set_bit = xor1 & ~(xor1 - 1);
        
        // Divide elements into two sets by comparing set_bit of xor1
        for(int i = 0; i < n; i++) {
            if(nums[i] & set_bit) {
                x ^= nums[i];
            }
            else {
                y ^= nums[i];
            }
        }

        return {x, y};
    }
};