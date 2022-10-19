/*
	Top K Frequent Words
	https://leetcode.com/problems/top-k-frequent-words/description/
*/

// Solution 1: Hashmap + Sorting

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto &word: words) {
            mp[word]++;
        }
        
        vector<pair<int, string>> vp;
        for(auto it: mp) {
            vp.push_back({it.second, it.first});
        }
        
        sort(vp.begin(), vp.end(), [&](pair<int, string> a, pair<int, string> b){
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        
        vector<string> res;
        for(auto &x: vp) {
            res.push_back(x.second);
            if(res.size() == k) {
                break;
            }
        }
        
        return res;
    }
};