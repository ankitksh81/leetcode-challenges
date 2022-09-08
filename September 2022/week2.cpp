/*
	Design Hit Counter
	https://leetcode.com/problems/design-hit-counter/
*/

// Solution 1: Queue

class HitCounter {
    queue<int> q;
public:
    HitCounter() {}
    
    void hit(int timestamp) {
        q.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while (!q.empty() && timestamp - q.front() >= 300) {
            q.pop();
        }
        
        return q.size();
    }
};


// Solution 2: Queue of Pairs

class HitCounter {
    int total;
    queue<pair<int, int>> hits;
public:
    HitCounter() : total(0) {}
    
    void hit(int timestamp) {
        if (hits.empty() || hits.back().first != timestamp) {
            hits.push({timestamp, 1});
        }
        else {
            hits.back().second++;
        }
        total++;
    }
    
    int getHits(int timestamp) {
        while (!hits.empty() && timestamp - hits.front().first >= 300) {
            total -= hits.front().second;
            hits.pop();
        }
        
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */