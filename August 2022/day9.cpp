/*
	Binary Trees With Factors
	https://leetcode.com/problems/binary-trees-with-factors/
*/

// Solution: Dynamic Programming

class Solution {
    const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int N = arr.size();
        long long ans = 0;
        
        unordered_map<int, long long> mp;
        for (int x : arr) {
            long long ways = 1;
            double lim = sqrt(x);
            for (int j = 0, fA = arr[0]; fA <= lim; fA = arr[++j]) {
                if (x % fA != 0) continue;
                int fB = x / fA;
                if (mp.find(fB) != mp.end()) {
                    ways = (ways + mp[fA] * mp[fB] * (fA == fB ? 1 : 2)) % MOD;
                }
            }
            
            mp[x] = ways;
            ans = (ans + ways) % MOD;
        }
        
        return (int)ans;
    }
};