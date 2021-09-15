// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3976/


// Solution 1:

class Solution {
    int comp(int a, int b) {
        if(a > b) {
            return 1;
        }
        else if(a < b) {
            return -1;
        }
        return 0;
    }
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 1, idx = 0;
        
        for(int i = 1; i < n; i++) {
            int c = comp(arr[i-1], arr[i]);
            
            if(c == 0) {
                idx = i;
            }
            else if(i == n-1 || c * comp(arr[i], arr[i+1]) != -1) {
                ans = max(ans, i - idx + 1);
                idx = i;
            }
        }
        return ans;
    }
};