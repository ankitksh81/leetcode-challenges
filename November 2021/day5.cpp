/*
    Arranging Coins
    https://leetcode.com/problems/arranging-coins/
*/

// Solution 1:

class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0, r = n;
        long cur_sum;
        while(l <= r) {
            long mid = l + (r - l) / 2;
            cur_sum = mid * (mid + 1) / 2;
            
            if(cur_sum == n) {
                return (int)mid;
            }
            
            if(cur_sum > n) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return (int)r;
    }
};

// Solution 2:

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt(2 * (long)n + 0.25) - 0.5);
    }
};