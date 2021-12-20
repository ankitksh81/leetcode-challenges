/*
    Minimum absolute difference
    https://leetcode.com/problems/minimum-absolute-difference/
*/

// Solution 1: Sorting + 2 Traversals

class Solution {
public:
    int findMinDiff(vector<int>& arr) {
        int minDif = INT_MAX;
        for(int i = 1; i < arr.size(); i++) {
            minDif = min(minDif, arr[i] - arr[i-1]);
        }
        
        return minDif;
    }
    
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = findMinDiff(arr);
        vector<vector<int>> minAbsDiffs;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i-1] == minDiff) {
                minAbsDiffs.push_back({arr[i-1], arr[i]});
            }
        }
        
        return minAbsDiffs;
    }
};

// Solution 2: Sorting + 1 Traversal

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;

        int minDif = arr[1] - arr[0];
        res.push_back({arr[0], arr[1]});
        
        for(int i = 2; i < arr.size(); i++) {
            int curDif = arr[i] - arr[i-1];
            if(curDif < minDif) {
                res.clear();
                res.push_back({arr[i-1], arr[i]});
                minDif = curDif;
            }
            else if(curDif == minDif) {
                res.push_back({arr[i-1], arr[i]});
            }
        }
        
        return res;
    }
};