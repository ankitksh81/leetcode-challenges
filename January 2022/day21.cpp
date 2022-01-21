/*
	Gas Station
	https://leetcode.com/problems/gas-station/
*/

// Solution:

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_tank = 0, cur_tank = 0, start = 0;
        for(int i = 0; i < n; i++) {
            total_tank += gas[i] - cost[i];
            cur_tank += gas[i] - cost[i];
            
            if(cur_tank < 0) {
                start = i + 1;
                cur_tank = 0;
            }
        }
        
        return total_tank >= 0 ? start : -1;
    }
};