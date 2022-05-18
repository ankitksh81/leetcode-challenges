/*
	Critical Connections in a Network
	https://leetcode.com/problems/critical-connections-in-a-network/
*/

// Solution: Articulation Point & DFS

class Solution {
    vector<int> discoveryTime, lowestTime;
    int time = 1;
    vector<vector<int>> result, adj;
public:
    void dfs(int curNode, int prevNode) {
        discoveryTime[curNode] = lowestTime[curNode] = time++;

        for (int nextNode : adj[curNode]) {
            if (discoveryTime[nextNode] == 0) {
                dfs(nextNode, curNode);
                lowestTime[curNode] = min(lowestTime[curNode], lowestTime[nextNode]);
            }
            else if (nextNode != prevNode) {
                lowestTime[curNode] = min(lowestTime[curNode], discoveryTime[nextNode]);
            }

            if (lowestTime[nextNode] > discoveryTime[curNode]) {
                result.push_back({curNode, nextNode});
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        discoveryTime = vector<int>(n);
        lowestTime = vector<int>(n);
        adj.resize(n);

        for (vector<int> &connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }

        dfs(0, -1);
        return result;
    }
};