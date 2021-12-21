/*
    Power of two
    https://leetcode.com/problems/power-of-two/
*/

// Solution 1:

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        
        int x = n;
        x |= (x >> 1);
        x |= (x >> 2);
        x |= (x >> 4);
        x |= (x >> 8);
        x |= (x >> 16);
        
        x = x ^ (x >> 1);
        return (n == x);
    }
};

// Solution 2:

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) {
            return false;
        }
        
        return (n & (n-1) ? false : true);
    }
};