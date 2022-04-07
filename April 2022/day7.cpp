/*
	Last Stone Weight
	https://leetcode.com/problems/last-stone-weight/
*/

// Solution 1: Max Heap

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) {
            return stones[0];
        }
        
        priority_queue<int> pq;
        for(int x : stones) {
            pq.push(x);
        }
        
        while(pq.size() > 1) {
            int mx1 = pq.top(); pq.pop();
            int mx2 = pq.top(); pq.pop();
            
            if(mx1 == mx2) {
                continue;
            }
            else {
                pq.push(mx1 - mx2);
            }
        }
        
        return pq.size() == 1 ? pq.top() : 0;
    }
};

// Solution 2:

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int maxWeight = stones[0];
        for(int stone: stones) {
            maxWeight = max(maxWeight, stone);
        }
        
        vector<int> buckets(maxWeight + 1);
        
        for(int weight : stones) {
            buckets[weight]++;
        }
        
        int biggestWeight = 0;
        int curWeight = maxWeight;
        while(curWeight > 0) {
            if(buckets[curWeight] == 0) {
                curWeight--;
            }
            else if(biggestWeight == 0) {
                buckets[curWeight] %= 2;
                if(buckets[curWeight] == 1) {
                    biggestWeight = curWeight;
                }
                curWeight--;
            }
            else {
                buckets[curWeight]--;
                if(biggestWeight - curWeight <= curWeight) {
                    buckets[biggestWeight - curWeight]++;
                    biggestWeight = 0;
                }
                else {
                    biggestWeight -= curWeight;
                }
            }
        }
        
        return biggestWeight;
    }
};