/*
    Merge Intervals
    https://leetcode.com/problems/merge-intervals/
*/

// Solution:

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){
            return a.front() < b.front();
        });
        
        vector<int> interval = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] <= interval[1]) {
                interval[1] = max(interval[1], intervals[i][1]);
            }
            else {
                mergedIntervals.push_back(interval);
                interval = intervals[i];
            }
        }
        mergedIntervals.push_back(interval);
        return mergedIntervals;
    }
};