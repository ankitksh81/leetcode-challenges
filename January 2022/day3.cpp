/*
    Find the town judge
    https://leetcode.com/problems/find-the-town-judge/
*/

// Solution:

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < n-1) {
            return -1;
        }
        vector<int> count(n+1);
        for(auto rel: trust) {
            count[rel[0]]--;
            count[rel[1]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(count[i] == n-1) {
                return i;
            }
        }
        
        return -1;
    }
};