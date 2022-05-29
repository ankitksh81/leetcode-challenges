/*
	Parallel Courses
	https://leetcode.com/problems/parallel-courses/
*/

// Solution: BFS + Topological Sort

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> adj[n+1], indegree(n+1);
        for (vector<int> &rel : relations) {
            int prevCourse = rel[0], nextCourse = rel[1];
            adj[prevCourse].push_back(nextCourse);
            indegree[nextCourse]++;
        }
        
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int reqSem = 0;
        int cnt = 0;
        
        while (!q.empty()) {
            int qsize = q.size();
            reqSem++;
            for (int i = 0; i < qsize; i++) {
                int course = q.front();
                q.pop();
                
                cnt++;
                for (auto neighbor : adj[course]) {
                    if (--indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        return cnt == n ? reqSem : -1;
    }
};