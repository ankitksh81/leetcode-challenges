/*
	Partition Labels
	https://leetcode.com/problems/partition-labels/
*/

// Solution: Two Pointers & Greedy

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int size = s.length();
        vector<int> last(26, -1), ans;
        
        for(int i = 0; i < size; i++) {
            last[s[i] - 'a'] = i;
        }
        
        int i = 0;
        while(i < size) {
            int res = last[s[i] - 'a'];
            int j = i;
            while(j < res) {
                res = max(res, last[s[j] - 'a']);
                j++;
            }
            ans.push_back(j - i + 1);
            i = j + 1;
        }
        
        return ans;
    }
};