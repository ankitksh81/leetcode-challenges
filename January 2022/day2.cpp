/*
    Pairs of Songs with total durations divisible by 60
    https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
*/

// Solution: Hash Map

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int pairs = 0;
        unordered_map<int, int> mp;
        for(int t: time) {
            int rem = t % 60;
            int val = (rem > 0 ? 60 - rem : 0);
            if(mp.find(val) != mp.end()) {
                pairs += mp[val];
            }
            mp[rem]++;
        }
        
        return pairs;
    }
};