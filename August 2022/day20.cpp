/*
	Minimum Number of Refueling Stops
	https://leetcode.com/problems/minimum-number-of-refueling-stops/
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long> dp(n + 10);
        dp[0] = startFuel;
        
        for(int i = 0; i < n; i++) {
            for(int t = i; t >= 0; t--) {
                if(dp[t] >= stations[i][0]) {
                    dp[t + 1] = max(dp[t + 1], dp[t] + (long)stations[i][1]);
                }
            }
        }
        
        for(int i = 0; i <= n; i++) {
            if(dp[i] >= target) {
                return i;
            }
        }
        
        return -1;
    }
};


// Solution 2: Greedy + Max Heap

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        if(startFuel - target >= 0) {
            return 0;
        }
        if(startFuel - target < 0 && n == 0) {
            return -1;
        }
        int stops = 0;
        long long curFuel = startFuel;
        priority_queue<int> pq;
        
        for(auto station: stations) {
            int pos = station[0];
            int fuel = station[1];
            if(curFuel < pos) {
                while(!pq.empty() && curFuel < pos) {
                    stops++;
                    curFuel += pq.top();
                    pq.pop();
                }
                
                if(curFuel < pos) {
                    return -1;
                }
            }
            if(curFuel == pos) {
                if(!pq.empty() && pq.top() > fuel) {
                    stops++;
                    curFuel += pq.top();
                    pq.pop();
                }
                else {
                    curFuel += fuel;
                    stops++;
                    continue;
                }
            }
            if(curFuel > pos) {
                pq.push(fuel);
            }
        }
        
        // last station to target
        int last_station = stations[n-1][0];
        int last_fuel = stations[n-1][1];
        while(!pq.empty() && curFuel < target) {
            curFuel += pq.top();
            pq.pop();
            stops++;
        }
        
        if(curFuel < target) {
            return -1;
        }
        
        return stops;
    }
};