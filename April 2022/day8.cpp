/*
	Kth Largest Element in a Stream
	https://leetcode.com/problems/kth-largest-element-in-a-stream/
*/

// Solution: Using Min Heap

class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
        if(pq.size() >= k) {
            if(val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }
        pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */