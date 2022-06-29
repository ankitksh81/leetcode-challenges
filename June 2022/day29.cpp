/*
	Queue Reconstruction by Height
	https://leetcode.com/problems/queue-reconstruction-by-height/
*/

// Solution: Greedy + Sorting

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int N = people.size();
        vector<vector<int>> result;
        
        sort(begin(people), end(people), [](vector<int>& a, vector<int>& b) {
            return (a[0] == b[0]) ? a[1] < b[1] : a[0] > b[0];
        });
        
        for (int i = 0; i < N; i++) {
            int pos = people[i][1];
            result.insert(result.begin() + pos, people[i]);
        }
        
        return result;
    }
};