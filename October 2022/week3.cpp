/*
	Similar RGB Color
	https://leetcode.com/problems/similar-rgb-color/
*/

// Solution:

class Solution {
public:
    string findTarget(string color) {
        int num = stoi(color, nullptr, 16);
        int x = round(num * 1.0 / 17);
        
        string ans;
        ans = x > 9 ? 'a' + x - 10 : '0' + x;
        
        return ans + ans;
    }
    
    string similarRGB(string color) {
        string targetColor = "#";
        
        for (int i = 1; i < 6; i += 2) {
            targetColor += findTarget(color.substr(i, 2));
        }
        
        return targetColor;
    }
};