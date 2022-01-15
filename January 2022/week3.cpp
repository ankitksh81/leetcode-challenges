/*
	Meeting Rooms II
	https://leetcode.com/problems/meeting-rooms-ii/
*/

// Solution 1: Priority Queue

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
};

// Solution 2: Chronological Ordering

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) {
            return 0;
        }
        
        vector<int> start(intervals.size()), end(intervals.size());
        for(int i = 0; i < intervals.size(); i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        
        sort(start.begin(), start.end(), [&](int a, int b){
            return a < b;
        });
        sort(end.begin(), end.end(), [&](int a, int b){
            return a < b;
        });
        
        int i = 0, j = 0, usedRooms = 0;
        while(i < intervals.size()) {
            if(start[i] >= end[j]) {
                usedRooms -= 1;
                j += 1;
            }
            usedRooms += 1;
            i += 1;
        }
        
        return usedRooms;
    }
};