/*
    Smallest integer divisible by k
    https://leetcode.com/problems/smallest-integer-divisible-by-k/
*/

// Solution 1:

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        
        int len = 1, x = 1;
        while(x % k != 0) {
            int n = x * 10  + 1;
            x = n % k;
            len += 1;
        }
        
        return len;
    }
};


// Solution 2:

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int x = 0;
        for(int l = 1; l <= k; l++) {
            x = (x * 10 + 1) % k;
            if(x == 0) {
                return l;
            }
        }
        
        return -1;
    }
};