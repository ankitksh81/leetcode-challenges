/*
	Put Boxes Into the Warehouse I
	https://leetcode.com/problems/put-boxes-into-the-warehouse-i/
*/

// Solution: Greedy + Sorting

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int N = boxes.size();
        
        for (int i = 1; i < warehouse.size(); i++) {
            warehouse[i] = min(warehouse[i], warehouse[i-1]);
        }
        
        sort(boxes.begin(), boxes.end());
        
        int idx = 0;
        for (int i = warehouse.size()-1; i >= 0; i--) {
            if (idx < N && warehouse[i] >= boxes[idx]) {
                idx++;
            }
        }
        
        return idx;
    }
};