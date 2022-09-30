/*
	Kill Process
	https://leetcode.com/problems/kill-process/description/
*/

// Solution: Recursion

class Solution {
public:
    void dfs(int kill, unordered_map<int, vector<int>>& mp, vector<int>& killedProcesses) {
        for (auto process : mp[kill]) {
            killedProcesses.push_back(process);
            dfs(process, mp, killedProcesses);
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> mp; // process -> [child processes]
        int size = pid.size();
        int root;
        for (int i = 0; i < size; i++) {
            if (ppid[i] == 0) {
                root = pid[i];
                continue;
            }
            mp[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> killedProcesses;
        killedProcesses.push_back(kill);
        
        dfs(kill, mp, killedProcesses);
        return killedProcesses;
    }
};