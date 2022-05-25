/*
	Russian Doll Envelopes
	https://leetcode.com/problems/russian-doll-envelopes/
*/

// Solution 1: Sorting + Dynamic Programming

class Solution {
public:
    int lengthOfLIS(vector<int>& ar) {
        vector<int> dp;
        
        for (int i = 0; i < ar.size(); i++) {
            int ele = ar[i];
            int idx = lower_bound(dp.begin(), dp.end(), ele) - dp.begin();
            
            if (idx >= dp.size()) {
                dp.push_back(ele);
            }
            else {
                dp[idx] = ele;
            }
        }
        
        return dp.size();
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), 
             [](const vector<int> &v1, const vector<int> &v2) {
                 if (v1[0] == v2[0]) {
                     return v1[1] > v2[1];
                 }
                 return v1[0] < v2[0];
             });
        vector<int> secondDimension(envelopes.size());
        for (int i = 0; i < envelopes.size(); i++) {
            secondDimension[i] = envelopes[i][1];
        }
        return lengthOfLIS(secondDimension);
    }
};