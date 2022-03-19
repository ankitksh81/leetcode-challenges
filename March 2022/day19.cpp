/*
	Maximum Frequency Stack
	https://leetcode.com/problems/maximum-frequency-stack/
*/

// Solution: Hashmap of Stacks

class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        group[freq[val]].push(val);
    }
    
    int pop() {
        int x = group[maxFreq].top();
        group[maxFreq].pop();
        if(!group[freq[x]--].size()) {
            maxFreq--;
        }
        
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */