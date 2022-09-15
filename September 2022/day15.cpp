/*
        Find Original Array From Doubled Array
        https://leetcode.com/problems/find-original-array-from-doubled-array/
*/

// Solution: Hashmap

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        if(changed.size() & 1) {
            return {};
        }
        
        unordered_map<int, int> mp;
        for(int x : changed) {
            mp[x]++;
        }
        
        sort(begin(changed), end(changed));
        
        for(int x : changed) {
            int res = x * 2;
            if(mp[x] == 0) {
                continue;
            }
            
            if(mp[res] == 0) {
                return {};
            }
            
            mp[res]--;
            mp[x]--;
            ans.push_back(x);
        }
        
        return ans;
    }
};
