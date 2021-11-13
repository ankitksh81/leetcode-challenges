/*
    Daily temperatures
    https://leetcode.com/problems/daily-temperatures/
*/

// Solution:

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st; // {val, idx}
        
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }
            
            if(!st.empty()) {
                ans[i] = abs(i - st.top().second);
            }
            st.push({temperatures[i], i});
        }
        
        return ans;
    }
};