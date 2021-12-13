/*
    Consecutive characters
    https://leetcode.com/problems/consecutive-characters/
*/

// Solution:

class Solution {
public:
    int maxPower(string s) {
        if(s.length() == 1) {
            return 1;
        }
        int max_power = INT_MIN, cur_power = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i-1]) {
                cur_power++;
            }
            else {
                max_power = max(max_power, cur_power);
                cur_power = 1;
            }
        }
        if(cur_power > 1) {
            max_power = max(max_power, cur_power);
        }
        
        return max_power;
    }
};