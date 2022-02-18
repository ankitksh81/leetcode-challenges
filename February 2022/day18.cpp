/*
	Remove K Digits
	https://leetcode.com/problems/remove-k-digits/
*/

// Solution: Greedy Using Stacks

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char digit: num) {
            while(!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        // pop remaining k elements
        for(int i = 0; i < k; i++) {
            st.pop();
        }
        
        string result = "";
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        // trim leading zeros
        while(result.back() == '0') {
            result.pop_back();
        }
        
        reverse(result.begin(), result.end());
        
        return result == "" ? "0" : result;
    }
};