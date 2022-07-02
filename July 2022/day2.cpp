/*
	Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
	https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
*/

// Solution: Greedy + Sorting

class Solution {
    const int MOD = 1e9 + 7;
public:
    int getHeight(vector<int>& horizontalCuts, int h) {
        int N = horizontalCuts.size();
        int max_height = horizontalCuts[0];
        
        for (int i = 1; i < N; i++) {
            int cur_height = horizontalCuts[i] - horizontalCuts[i-1];
            if (cur_height > max_height) {
                max_height = cur_height;
            }
        }
        
        if (h - horizontalCuts[N-1] > max_height) {
            max_height = h - horizontalCuts[N-1];
        }
        
        return max_height;
    }
    
    int getWidth(vector<int>& verticalCuts, int w) {
        int N = verticalCuts.size();
        int max_width = verticalCuts[0];
        
        for (int i = 1; i < N; i++) {
            int cur_width = verticalCuts[i] - verticalCuts[i-1];
            if (cur_width > max_width) {
                max_width = cur_width;
            }
        }
        
        if (w - verticalCuts[N-1] > max_width) {
            max_width = w - verticalCuts[N-1];
        }
        
        return max_width;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long height = getHeight(horizontalCuts, h);
        long width = getWidth(verticalCuts, w);
        
        return (height * width) % MOD;
    }
};