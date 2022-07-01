/*
	Maximum Units on a Truck
	https://leetcode.com/problems/maximum-units-on-a-truck/
*/

// Solution: Greedy + Sorting

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });
        
        int maxUnits = min(truckSize, boxTypes[0][0]) * boxTypes[0][1];
        int remSize = truckSize - min(truckSize, boxTypes[0][0]);
        
        for(int i = 1; i < n; i++) {
            int numOfBoxes = boxTypes[i][0];
            int units = boxTypes[i][1];
            
            if(remSize > 0) {
                maxUnits += min(numOfBoxes, remSize) * units;
                remSize -= min(numOfBoxes, remSize);
            }
            else {
                break;
            }
        }
        return maxUnits;
    }
};