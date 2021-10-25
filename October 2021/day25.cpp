/*
    Min stack
    https://leetcode.com/problems/min-stack/
*/

// Solution:

class MinStack {
    stack<pair<int, int>> st; // <top, min>
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        }
        else {
            int min_ele = (st.top().second <= val ? st.top().second : val);
            st.push({val, min_ele});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */