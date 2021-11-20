/*
    Single element in a sorted array
    https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

// Solution: Xor

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int x: nums){
            ans ^= x;
        }
        return ans;
    }
};