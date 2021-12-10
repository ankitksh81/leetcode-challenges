/*
    Domino and Tromino Tiling
    https://leetcode.com/problems/domino-and-tromino-tiling/
*/

// Solution 1: Top-Down

class Solution {
    int MOD = 1e9+7;
    long full[1005], partial[1005];   
public:
    long solvePartial(int n) {
        if(n == 2) {
            return 1L;
        }
        
        if(partial[n] != -1) {
            return partial[n];
        }
        
        return partial[n] = (solvePartial(n-1) + solveFull(n-2)) % MOD;
    }
    
    long solveFull(int n) {
        if(n == 1) {
            return 1L;
        } else if(n == 2) {
            return 2L;
        }
        
        if(full[n] != -1) {
            return full[n];
        }
        
        return full[n] = (solveFull(n-1) + solveFull(n-2) + 
            2 * solvePartial(n-1)) % MOD;
    }
    
    int numTilings(int n) {
        memset(full, -1, sizeof(full));
        memset(partial, -1, sizeof(partial));
        
        return (int)(solveFull(n));
    }
};

// Solution 2: Bottom-Up

class Solution {
    int MOD = 1e9+7;
public:
    int numTilings(int n) {
        if(n <= 2) {
            return n;
        }
        vector<long> full(n+1), partial(n+1);
        full[1] = partial[2] = 1L;
        full[2] = 2L;
        
        for(int i = 3; i <= n; i++) {
            full[i] = (full[i-1] + full[i-2] + 2*partial[i-1]) % MOD;
            partial[i] = (partial[i-1] + full[i-2]) % MOD;
        }
        
        return (int)(full[n]);
    }
};