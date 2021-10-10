/*
    Bitwise AND of numbers range
    https://leetcode.com/problems/bitwise-and-of-numbers-range/
*/

// Solution 1:

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bitset<32> b1(left), b2(right), b3(0);
        for(int i = 31; i >= 0; i--) {
            if(b1[i] == b2[i]) {
                b3[i] = b1[i];
            }
            else {
                break;
            }
        }
        return b3.to_ulong();
    }
};


// Solution 2:

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int cnt = 0;
        while(left != right) {
            left = left >> 1;
            right = right >> 1;
            cnt++;
        }
        return left << cnt;
    }
};