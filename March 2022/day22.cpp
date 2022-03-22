/*
	Smallest String With A Given Numeric Value
	https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
*/

// Solution: Greedy

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;
        
        if (k == 0) {
            return ans;
        }
        
        for (int i = n-1; i >= 0; i--) {
            if (k > 25) {
                k -= 25;
                ans[i] = 'z';
            }
            else {
                char c = (k + 'a');
                ans[i] = c;
                break;
            }
        }
        
        return ans;
    }
};