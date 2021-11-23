/*
    Largest component size by common factor
    https://leetcode.com/problems/largest-component-size-by-common-factor/
*/

// Solution:

class Solution {
    struct DSU {
        vector<int> par;
        int n;
        
        DSU(int _n): n(_n) {
            for(int i = 0; i < n; i++) {
                par.push_back(i);
            }
        }
        
        int find(int a) {
            if(a == par[a]) {
                return a;
            }
            return par[a] = find(par[a]);
        }
        
        bool join(int a, int b) {
            a = find(a);
            b = find(b);
            
            par[a] = b;
            return (a != b);
        }
    };
public:
    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        DSU dsu(n+1);
        
        for(int num: nums) {
            for(int i = 2; i <= sqrt(num); i++) {
                if(num % i == 0) {
                    dsu.join(i, num);
                    dsu.join(num, num / i);
                }
            }
        }
        
        unordered_map<int, int> mp;
        int ans = 1;
        for(int num: nums) {
            ans = max(ans, ++mp[dsu.find(num)]);
        }
        
        return ans;
    }
};