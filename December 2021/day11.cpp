/*
    Nth magical number
    https://leetcode.com/problems/nth-magical-number/
*/

// Solution 1: Binary search

class Solution {
    int MOD = 1e9 + 7;
public:
    int findLCM(int a, int b) {
        return (a * b) / __gcd(a, b);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = findLCM(a, b);
        
        long l = 0, h = (long)(n * (long)min(a, b));
        while(l < h) {
            long mid = l + (h - l) / 2;
            // if not enough magic numbers below mid
            if(mid / a + mid / b - mid / lcm < n) {
                l = mid + 1;
            }
            else {
                h = mid;
            }
        }
        
        return (int)(l % MOD);
    }
};

// Solution 2: Maths

class Solution {
    int MOD = 1e9 + 7;
public:
    int findLCM(int a, int b) {
        return (a * b) / __gcd(a, b);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = findLCM(a, b);
        int m = lcm / a + lcm / b - 1;
        int q = n / m, r = n % m;
        
        long ans = (long)q * (long)lcm % MOD;
        if (r == 0) {
            return (int)ans;
        }
        
        int heads[2] = {a, b};
        for(int i = 0; i < r - 1; i++) {
            if(heads[0] <= heads[1]) {
                heads[0] += a;
            } else {
                heads[1] += b;
            }
        }
        
        ans += min(heads[0], heads[1]);
        return (int)(ans % MOD);
    }
};