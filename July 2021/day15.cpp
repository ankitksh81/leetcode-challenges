/* Day 15
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3815/
*/


// Solution 1:

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        
        for(int i = 2; i < nums.size(); i++) {
            int val = nums[i];
            int l = 0, r = i-1;
            
            while(l < r) {
                if(nums[l] + nums[r] > val) {
                    ans += (r - l);
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    int triangleNumber(vector<int>& a) {
        int f[1001], pref[1001], ans = 0;
        memset(f, 0, sizeof(f));
        memset(pref, 0, sizeof(pref));
        
        for(auto ii: a) {
            f[ii]++;
        }
        
        pref[0] = 0;
        for(int i = 1; i <= 1000; i++) {
            pref[i] = pref[i-1] + f[i];
        }
        
        int i, j, l, r;
        for(i = 2; i <= 998; i++) {
            if(f[i] == 0)
                continue;
            for(j = i+1; j < 1000; j++) {
                l = j+1;  
                r = min(i+j-1, 1000);
                ans += (pref[r] - pref[l-1]) * f[i] * f[j];
            }
        }
        
        for(i = 1; i <= 1000; i++) {
            if(f[i] > 2) {
                int v = f[i];
                v = (v * (v-1)*(v-2)) / 6;
                ans += v;
            }
        }
        
        for(i = 1; i <= 1000; i++) {
            if(f[i] > 1) {
                l = 1, r = 2*i-1;
                r = min (r, 1000);
                int v = ((f[i] * (f[i]-1)) / 2);
                ans += (pref[r] - f[i]) * v;
                if(i == 4) {
                }
            }
        }
        return ans;
    }
};
