/*
	Validate Stack Sequences
	https://leetcode.com/problems/validate-stack-sequences/
*/

// Solution: Simulation

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int size = popped.size(), j = 0;
        
        for (int ele : pushed) {
            st.push(ele);
            
            while (!st.empty() && j < size && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        
        return j == size;
    }
};