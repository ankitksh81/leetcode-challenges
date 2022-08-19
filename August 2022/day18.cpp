/*
	Reduce Array Size to The Half
	https://leetcode.com/problems/reduce-array-size-to-the-half/
*/

// Solution: Hashmap

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int N = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        
        vector<int> v;
        for (auto &[k, val] : freq) {
            v.push_back(val);
        }
        
        sort(v.rbegin(), v.rend());
        int res = 0, cnt = N;
        
        for (int i = 0; i < v.size(); i++) {
            cnt -= v[i];
            if (cnt <= N/2) {
                res = i+1;
                break;
            }
        }
        
        return res;
    }
};