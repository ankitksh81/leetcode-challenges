/*
	Campus Bikes
	https://leetcode.com/problems/campus-bikes/
*/

// Solution 1: Sorting

struct Node {
    int distance, worker, bike;
    
    Node(int d, int w, int b) : distance(d), worker(w), bike(b) {}
};

inline static bool comparator(Node a, Node b) {
    if (a.distance == b.distance) {
        if (a.worker == b.worker) {
            return a.bike < b.bike;
        }
        return a.worker < b.worker;
    }
    return a.distance < b.distance;
}

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<Node> nodes;
        
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0;  j < bikes.size(); j++) {
                int dist = abs(workers[i][1] - bikes[j][1]) + 
                    abs(workers[i][0] - bikes[j][0]);
                nodes.push_back(Node(dist, i, j));
            }
        }
        
        sort(nodes.begin(), nodes.end(), comparator);
        
        vector<int> ans(workers.size(), -1);
        unordered_set<int> taken;
        
        for (auto &node : nodes) {
            if (ans[node.worker] == -1 && taken.find(node.bike) == taken.end()) {
                ans[node.worker] = node.bike;
                taken.insert(node.bike);
            }
        }
        
        return ans;
    }
};

// Solution 2: Bucket Sort

class Solution {
public:
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int minDist = INT_MAX;
        vector<pair<int, int>> distToPairs[1999];
        
        for (int worker = 0; worker < workers.size(); worker++) {
            for (int bike = 0; bike < bikes.size(); bike++) {
                int distance = findDistance(workers[worker], bikes[bike]);
                distToPairs[distance].push_back({worker, bike});
                minDist = min(minDist, distance);
            }
        }
        
        int curDist = minDist;
        vector<bool> bikeStatus(bikes.size(), false);
        vector<int> workerStatus(workers.size(), -1);
        
        int pairCount = 0;
        
        while (pairCount != workers.size()) {
            for (auto &[worker, bike] : distToPairs[curDist]) {
                if (workerStatus[worker] == -1 && !bikeStatus[bike]) {
                    bikeStatus[bike] = true;
                    workerStatus[worker] = bike;
                    pairCount++;
                }
            }
            curDist++;
        }
        
        return workerStatus;
    }
};