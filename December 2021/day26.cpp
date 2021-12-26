/*
    K closest points to origin
    https://leetcode.com/problems/k-closest-points-to-origin/
*/

// Solution 1: Max heap

class Solution {
public:
    int squaredDist(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < points.size(); i++) {
            pair<int, int> entry = {squaredDist(points[i]), i};
            if(pq.size() < k) {
                pq.push(entry);
            }
            else if(entry.first < pq.top().first) {
                pq.pop();
                pq.push(entry);
            }
        }
        
        vector<vector<int>> ans;
        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(points[idx]);
        }
        return ans;
    }
};

// Solution 2: Binary search

class Solution {
public:
    double euclideanDistance(vector<int>& point) {
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }
    
    vector<vector<int>> splitDistances(vector<int>& remaining, vector<double>& dist, double mid) {
        vector<vector<int>> result(2);
        vector<int> &closer = result[0], &farther = result[1];
        for(int idx: remaining) {
            if(dist[idx] <= mid) {
                closer.push_back(idx);
            }
            else {
                farther.push_back(idx);
            }
        }
        return result;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<double> dist;
        vector<int> remaining;
        double low = 0, high = 0;
        for(int i = 0; i < points.size(); i++) {
            dist.push_back(euclideanDistance(points[i]));
            high = max(high, dist[i]);
            remaining.push_back(i);
        }
        
        vector<int> closest;
        while(k) {
            double mid = low + (high - low) / 2;
            vector<vector<int>> result = splitDistances(remaining, dist, mid);
            vector<int>& closer = result[0];
            vector<int>& farther = result[1];
            if(closer.size() > k) {
                remaining.swap(closer);
                high = mid;
            } else {
                k -= closer.size();
                closest.insert(closest.end(), closer.begin(), closer.end());
                remaining.swap(farther);
                low = mid;
            }
        }
        
        vector<vector<int>> ans;
        for(int idx: closest) {
            ans.push_back(points[idx]);
        }
        return ans;
    }
};