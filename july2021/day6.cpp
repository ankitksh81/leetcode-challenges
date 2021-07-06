/* Day 6
    Question link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3804/
*/

// Solution 1

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int ar[1000005] = {0};
        vector<pair<int, int>> vp;
        set<int> s;

        for(int i: arr) {
            ar[i]++;
        }

        for(int i = 0; i < 1000005; i++) {
            if(ar[i]) {
                vp.push_back({ar[i], i});
            }
        }

        int removed = 0;
        sort(vp.begin(), vp.end());

        for(auto it = vp.rbegin(); it != vp.rend(); it++) {
            if(removed < n/2) {
                s.insert(it->second);
                removed += it->first;
            }
            if(removed >= n/2)  break;
        }

        return s.size();
    }
};

// Solution 2

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int maxi = 0;
        for(int i = 0 ; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }
        vector<int> map(maxi+1, 0);
        for(int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }
        vector<int> freq;
        for(int i = 1; i <= maxi; i++) {
            if(map[i]) {
                freq.push_back(map[i]);
            }
        }

        sort(freq.begin(), freq.end());
        int ans = 0, sum = 0;
        for(int i = freq.size() - 1; i > -1; i--) {
            sum += freq[i];
            ans++;
            if(sum >= arr.size()/2) {
                return ans;
            }
        }
        return ans;
    }
};
