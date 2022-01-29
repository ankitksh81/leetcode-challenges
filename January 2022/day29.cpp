/*
	Largest Rectangle in Histogram
	https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

// Solution: Stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i <= n; i++) {
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(!st.empty()) {
                    width = i - st.top() - 1;
                }
                else {
                    width = i;
                }
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};