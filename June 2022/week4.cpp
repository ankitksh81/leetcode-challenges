/*
	Meeting Scheduler
	https://leetcode.com/problems/meeting-scheduler/
*/

// Solution 1: Two Pointers

class Solution {
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return (a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]);
    }
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        int N = slots1.size(), M = slots2.size();
        
        sort(slots1.begin(), slots1.end(), cmp);
        sort(slots2.begin(), slots2.end(), cmp);
        
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < N && ptr2 < M) {
            int l = max(slots1[ptr1][0], slots2[ptr2][0]);
            int r = min(slots1[ptr1][1], slots2[ptr2][1]);
            
            if (r - l >= duration) {
                return {l, l + duration};
            }
            
            if (slots1[ptr1][1] < slots2[ptr2][1]) {
                ptr1++;
            }
            else {
                ptr2++;
            }
        }
        
        return {};
    }
};


// Solution 2: Heap

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        for (auto s : slots1) {
            if (s[1] - s[0] >= duration) q.push({ s[0], s[1] });
        }
        
        for (auto s : slots2) {
            if (s[1] - s[0] >= duration) q.push({ s[0], s[1] });
        }
        
        while (q.size() > 1) {
            auto end1 = q.top().second;
            q.pop();
            auto start2 = q.top().first;
            if (end1 >= start2 + duration)
                return { start2, start2 + duration };
        }
        
        return {};
    }
};