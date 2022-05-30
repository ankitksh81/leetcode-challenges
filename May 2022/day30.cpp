/*
	Divide Two Integers
	https://leetcode.com/problems/divide-two-integers/
*/

// Solution 1: Repeated Exponential Searches

class Solution {
    int HALF_INT_MIN = INT_MIN / 2;
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }
        
        int quotient = 0;
        while (divisor >= dividend) {
            int powerOfTwo = -1;
            int val = divisor;
            
            while (val >= HALF_INT_MIN && val + val >= dividend) {
                val += val;
                powerOfTwo += powerOfTwo;
            }
            
            quotient += powerOfTwo;
            dividend -= val;
        }
        
        if (negatives != 1) {
            quotient = -quotient;
        }
        
        return quotient;
    }
};

// Solution 2: Binary Long Divison

class Solution {
    int HALF_INT_MIN = INT_MIN / 2;
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }
        
        int maxBit = 0;
        while (divisor >= HALF_INT_MIN && divisor + divisor >= dividend) {
            maxBit += 1;
            divisor += divisor;
        }
        
        int quotient = 0;
        for (int bit = maxBit; bit >= 0; bit--) {
            if (divisor >= dividend) {
                quotient -= (1 << bit);
                dividend -= divisor;
            }
            
            divisor = (divisor + 1) >> 1;
        }
        
        if (negatives != 1) {
            quotient = -quotient;
        }
        
        return quotient;
    }
};