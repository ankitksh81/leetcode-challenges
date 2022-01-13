/*
	Minimum Number of Arrows to Burst Balloons
	https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/

// Solution: Sorting

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int minArrows = 1;
        sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<int> last = points[0];
        for(int i = 1; i < points.size(); i++) {
            if(points[i][1] <= last[1]) {
                last[1] = points[i][1];
            }
            else if(points[i][0] <= last[1]) {
                last[0] = points[i][0];
            }
            else {
                minArrows++;
                last = points[i];
            }
        }
        
        return minArrows;
    }
};
