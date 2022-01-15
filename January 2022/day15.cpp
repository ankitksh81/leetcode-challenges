/*
	Jump Game IV
	https://leetcode.com/problems/jump-game-iv/
*/

// Solution: BFS

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> sameVal;
        for(int i = 0; i < arr.size(); i++) {
            sameVal[arr[i]].push_back(i);
        }
        
        queue<pair<int, int>> q;
        vector<int> shortestPath(arr.size(), INT_MAX);
        shortestPath[0] = 0;
        
        if(arr.size() == 1) {
            return 0;
        }
        
        q.push({0, 1});
        for(const auto &i: sameVal[arr[0]]) {
            if(i != 0) {
                q.push({0, i});
            }
        }
        
        while(!q.empty()) {
            auto [src, dest] = q.front();
            q.pop();
            shortestPath[dest] = min(shortestPath[dest], shortestPath[src] + 1);
            if(dest == arr.size() - 1) {
                return shortestPath[dest];
            }
            
            for(const auto &newDest: sameVal[arr[dest]]) {
                if(shortestPath[newDest] == INT_MAX) {
                    q.push({dest, newDest});
                }
            }
            
            sameVal[arr[dest]].clear();
            
            if(dest > 0 && shortestPath[dest - 1] == INT_MAX) {
                q.push({dest, dest-1});
            }
            if(dest < (arr.size() - 1) && shortestPath[dest + 1] == INT_MAX) {
                q.push({dest, dest + 1});
            }
        }
        
        return shortestPath[arr.size() - 1];
    }
};