/*
	Course Schedule III
	https://leetcode.com/problems/course-schedule-iii/
*/

// Solution: Max Heap

struct Node {
    int cost, end;
    bool operator < (const Node &obj) const {
        return end < obj.end;
    }
};

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int N = courses.size();
        vector<Node> arr = vector<Node>(N);
        
        for (int i = 0; i < N; i++) {
            arr[i] = Node{courses[i][0], courses[i][1]};
        }
        
        sort(arr.begin(), arr.end());
        int sum = 0;
        
        priority_queue<int> pq;
        for (const Node &x : arr) {
            if (sum + x.cost <= x.end) {
                pq.push(x.cost);
                sum += x.cost;
                
            } else {
                if (!pq.empty() && x.cost < pq.top()) {
                    sum -= pq.top() - x.cost;
                    pq.pop();
                    pq.push(x.cost);
                }
            }
        }
        
        return pq.size();
    }
};