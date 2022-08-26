/*
	Reordered Power of 2
	https://leetcode.com/problems/reordered-power-of-2/
*/

// Solution 1: Counting

class Solution {
    vector<int> count(int n) {
        vector<int> res(10);
        while (n > 0) {
            res[n % 10]++;
            n /= 10;
        }
        
        return res;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> cnt = count(n);
        for (int i = 0; i < 31; i++) {
            if (cnt == count(1 << i)) {
                return true;
            }
        }
        
        return false;
    }
};


// Solution 2: Sorting & Hashset

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        unordered_set<string> powerOfTwos;
        for (int i = 0; i < 32; ++i) {
            int n = 1 << i;
            string s = to_string(n);
            
            sort(s.begin(), s.end());
            powerOfTwos.insert(s);
        }
        
        string s = to_string(N);
        sort(s.begin(), s.end());
        
        return powerOfTwos.count(s) > 0;       
    }
};