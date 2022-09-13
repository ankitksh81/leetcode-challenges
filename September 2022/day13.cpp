/*
        UTF-8 Validation
        https://leetcode.com/problems/utf-8-validation/
*/

// Solution: Bit Manipulation

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int bytes = 0;
        int msb1 = 1 << 7;
        int msb2 = 1 << 6;
        
        for (int x : data) {
            if (bytes == 0) {
                int mask = 1 << 7;
                while ((mask & x) != 0) {
                    bytes++;
                    mask >>= 1;
                }
                
                if (bytes == 0) {
                    continue;
                }
                
                if (bytes > 4 || bytes == 1) return false;
            }
            else {
                if (!((msb1 & x) != 0 && (msb2 & x) == 0)) {
                    return false;
                }
            }
            
            bytes -= 1;
        }
        
        return bytes == 0;
    }
};
