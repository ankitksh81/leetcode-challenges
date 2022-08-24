/*
	Power of Three
	https://leetcode.com/problems/power-of-three/
*/

// Solution 1: Math

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        
        int k = ceil(log(n) / log(3));
        
        return n == pow(3, k);
    }
};


// Solution 2: Iterative Method

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) return false;
        
        while (n % 3 == 0) {
            n /= 3;
        }
        
        return n == 1;
    }
};