/*
	Top K Frequent Elements
	https://leetcode.com/problems/top-k-frequent-elements/
*/

// Solution: Min Heap

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	if(nums.size() == k) {
    		return nums;
    	}
    	
        unordered_map<int, int> freq;
        for(int x : nums) {
            freq[x]++;
        }
        
        auto cmp = [&freq](int a, int b) {
            return freq[a] > freq[b];
        };
        
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto it : freq) {
            pq.push(it.first);
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> res(k);
        for(int i = k-1; i >= 0; i--) {
            res[i] = pq.top();
            pq.pop();
        }
        
        return res;
    }
};