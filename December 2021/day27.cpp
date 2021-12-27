/*
    Number complement
    https://leetcode.com/problems/number-complement/
*/

// Solution:

class Solution {
public:
    int findComplement(int num) {
        int x = num, bit = 1;
        while(x != 0) {
            num ^= bit;
            bit <<= 1;
            x >>= 1;
        }
        
        return num;
    }
};