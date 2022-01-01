/*
    Maximum Vacation Days
    https://leetcode.com/problems/maximum-vacation-days/
*/

// Solution 1: DFS + DP

class Solution {
    int dp[105][105];
public:
    int dfs(vector<vector<int>>& flights, vector<vector<int>>& days, int city, int week) {
        if(week == days[0].size()) {
            return 0;
        }
        
        if(dp[city][week] != -1) {
            return dp[city][week];
        }
        
        int max_vac = 0;
        for(int i = 0; i < flights.size(); i++) {
            if(flights[city][i] == 1 || i == city) {
                int vac = days[i][week] + dfs(flights, days, i, week + 1);
                max_vac = max(max_vac, vac);
            }
        }
        
        return dp[city][week] = max_vac;
    }
    
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        memset(dp, -1, sizeof(dp));
        return dfs(flights, days, 0, 0);
    }
};

// Solution 2: 2D DP

class Solution {
    int dp[105][105];
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if(days.size() * flights.size() == 0) {
            return 0;
        }
        
        for(int week = days[0].size()-1; week >= 0; week--) {
            for(int city = 0; city < days.size(); city++) {
                dp[city][week] = days[city][week] + dp[city][week+1];
                
                for(int dest = 0; dest < days.size(); dest++) {
                    if(flights[city][dest] == 1) {
                        dp[city][week] = max(days[dest][week] + dp[dest][week+1], dp[city][week]);
                    }
                }
            }
        }
        
        return dp[0][0];
    }
};

// Solution 3: 1D DP

class Solution {
    vector<int> dp;
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        if(days.size() * flights.size() == 0) {
            return 0;
        }
        dp.resize(days.size());
        
        for(int week = days[0].size()-1; week >= 0; week--) {
            vector<int> temp(days.size());
            for(int city = 0; city < days.size(); city++) {
                temp[city] = days[city][week] + dp[city];
                
                for(int dest = 0; dest < days.size(); dest++) {
                    if(flights[city][dest] == 1) {
                        temp[city] = max(days[dest][week] + dp[dest], temp[city]);
                    }
                }
            }
            dp = temp;
        }
        
        return dp[0];
    }
};