/*
	Furthest Building You Can Reach
	https://leetcode.com/problems/furthest-building-you-can-reach/
*/

// Solution 1: Min Heap

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int N = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < N-1; i++) {
            int heightDiff = heights[i+1] - heights[i];
            if (heightDiff > 0) {
                pq.push(heightDiff);
            }
            
            if (pq.size() > ladders) {
                bricks -= pq.top();
                pq.pop();
            }
            
            if (bricks < 0) return i;
        }
        
        return N - 1;
    }
};


// Solution 2: Max Heap

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int N = heights.size();
        priority_queue<int> pq;
        
        for (int i = 0; i < N-1; i++) {
            int d = heights[i+1] - heights[i];
            if (d > 0) {
                pq.push(d);
                bricks -= d;
            }
            
            if (bricks < 0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            
            if (ladders < 0)    return i;
        }
        
        return N-1;
    }
};