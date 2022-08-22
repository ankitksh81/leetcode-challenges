/*
	Power of Four
	https://leetcode.com/problems/power-of-four/
*/

// Solution 1: Log

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) {
            return false;
        }
        
        long k = ceil(log(n) / log(4));
        long x = pow(4, k);
        
        return n == x;
    }
};


// Solution 2: Bit Manipulation

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && ((n & 0xaaaaaaaa) == 0);
    }
};


// Solution 3: Bit Manipulation + Maths

class Solution {
public:
    bool isPowerOfFour(int n) {
        return (n > 0) && ((n & (n - 1)) == 0) && (n % 3 == 1);
    }
};