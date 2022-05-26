/*
	Number of 1 Bits
	https://leetcode.com/problems/number-of-1-bits/
*/

// Solution 1: Count Number of Bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcountll(n);
    }
};

// Solution 2: Bit Manipulation

class Solution  {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while (n != 0) {
			cnt++;
			n &= (n-1);
		}
		return cnt;
	}
}