/*
	Maximum Performance of a Team
	https://leetcode.com/problems/maximum-performance-of-a-team/
*/

// Solution: Greedy + Min Heap

struct Engineer {
    int speed;
    int efficiency;
    
    Engineer(int speed, int efficiency) : speed(speed), efficiency(efficiency) {};
    
    bool operator<(const Engineer &obj1) {
        return (obj1.efficiency == efficiency ? obj1.speed < speed : obj1.efficiency < efficiency);
    }

};

class Solution {
    const int MOD = 1e9 + 7;
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<Engineer> eng;
        for (int i = 0; i < n; i++) {
            eng.push_back({speed[i], efficiency[i]});
        }
        
        sort(eng.begin(), eng.end());
        
        long long sum = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (Engineer &e : eng) {
            pq.push(e.speed);
            sum += e.speed;
            
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            res = max(res, sum * e.efficiency);
        }
        
        return res % MOD;
    }
};