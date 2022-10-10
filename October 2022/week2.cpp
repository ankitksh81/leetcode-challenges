/*
        Max Stack
        https://leetcode.com/problems/max-stack/description/
*/

// Solution 1: Balanced Trees

class MaxStack {
    set<pair<int, int>> st;
    set<pair<int, int>> values;
    int count;

public:
    MaxStack() {
        count = 0;    
    }
    
    void push(int x) {
        st.insert({count, x});
        values.insert({x, count});
        count++;
    }
    
    int pop() {
        pair<int, int> p = *st.rbegin();
        st.erase(p);
        values.erase({p.second, p.first});
        return p.second;
    }
    
    int top() {
        return st.rbegin()->second;
    }
    
    int peekMax() {
        return values.rbegin()->first;
    }
    
    int popMax() {
        pair<int, int> p = *values.rbegin();
        values.erase(p);
        st.erase({p.second, p.first});
        return p.first;
    }
};


// Solution 2: Heap + Stack

class MaxStack {
    stack<pair<int, int>> st;
    priority_queue<pair<int, int>> heap;
    unordered_set<int> removed;
    int count;
public:
    MaxStack() {
        count = 0;
    }
    
    void push(int x) {
        st.push({x, count});
        heap.push({x, count});
        count++;
    }
    
    int pop() {
        while (removed.count(st.top().second)) {
            st.pop();
        }

        const pair<int, int> p = st.top();
        st.pop();
        removed.insert(p.second);
        return p.first;
    }
    
    int top() {
        while (removed.count(st.top().second)) {
            st.pop();
        }
        return st.top().first;
    }
    
    int peekMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        return heap.top().first;
    }
    
    int popMax() {
        while (removed.count(heap.top().second)) {
            heap.pop();
        }
        const pair<int, int> p = heap.top();
        heap.pop();
        removed.insert(p.second);
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
