/* Day 2
    Question link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3800/
*/

// Solution 1:

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        map<int, queue<int> > mp;
        
        for(int i = 0; i < arr.size(); i++) {
            mp[abs(arr[i]-x)].push(arr[i]);
        }
        int temp = k;
        while(temp > 0){
            for(auto it = mp.begin(); it != mp.end(); it++) {
                while(temp > 0 && !mp[it->first].empty()){
                    int ele = mp[it->first].front();    
                    mp[it->first].pop();
                    ans.push_back(ele);
                    temp--;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Solution 2:

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size()-k;
        while (l < r) {
            int m = l + (r - l)/2;
            if (x - arr[m] > arr[m+k] - k) {
                l = m + 1;
            } else{
                r = m;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
