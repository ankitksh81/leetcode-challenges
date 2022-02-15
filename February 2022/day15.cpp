/*
	Single Number
	https://leetcode.com/problems/single-number/
*/

// Solution: Xor

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto a: nums) {
            x ^= a;
        }
        
        return x;
    }
};