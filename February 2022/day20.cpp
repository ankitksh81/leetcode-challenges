/*
	Remove Covered Intervals
	https://leetcode.com/problems/remove-covered-intervals/
*/

// Solution : Sorting + Greedy

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] >  b[1];
            }
            return a[0] < b[0];
        });
        
        int numOfIntervals = 0;
        int prev_end = 0, end;
        for(auto interval: intervals) {
            end = interval[1];
            if(prev_end < end) {
                ++numOfIntervals;
                prev_end = end;
            }
        }
        
        return numOfIntervals;
    }
};