/*
    Car Pooling
    https://leetcode.com/problems/car-pooling/
*/

// Solution: Bucket Sort

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> timestamp(1001);
        for(auto trip: trips) {
            timestamp[trip[1]] += trip[0];
            timestamp[trip[2]] -= trip[0];
        }
        
        int usedCapacity = 0;
        for(int num: timestamp) {
            usedCapacity += num;
            if(usedCapacity > capacity) {
                return false;
            }
        }
        
        return true;
    }
};