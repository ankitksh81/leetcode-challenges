/*
        Maximum Length of Repeated Subarray
        https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/

// Solution 1: Dynamic Programming

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size(), M = nums2.size();
        vector<vector<int>> dp(N+1, vector<int>(M+1));
        
        int res = 0;
        for (int i = N-1; i >= 0; i--) {
            for (int j = M-1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                    res = max(res, dp[i][j]);
                }
            }
        }
        
        return res;
    }
};


// Solution 2: Rolling Hash

class Hash {
    private:
    const long long kBase = 1949313259;
    const long long kMod = 2091573227;
public:
    int len;
    vector<long long> pwoer, hash;

    Hash(vector<int> &str) {
        len = str.size();
        pwoer.resize(len + 1, 1);
        hash.resize(len + 1, 0);

        for (int i = 1; i <= len; i++) {
            pwoer[i] = (pwoer[i - 1] * kBase) % kMod;
        }

        for (int i = 1; i <= len; i++) {
            hash[i] = (hash[i - 1] * kBase + str[i-1]) % kMod;
        }
    }

    ~Hash() {
        len = 0;
        pwoer.clear();
        hash.clear();
    }

    long long rangeHash(int l, int r) {
        long long result = (hash[r + 1] - hash[l] * pwoer[r - l + 1]) % kMod;
        if (result < 0) result += kMod;
        return result;
    }

};

class Solution {
    bool check(vector<int>& nums1, vector<int>& nums2, int mid, Hash &h1, Hash &h2) {
        unordered_set<int> st;
        for (int i = mid - 1; i < nums1.size(); i++) {
            st.insert(h1.rangeHash(i - mid + 1, i));
        }
        
        for (int i = mid - 1; i < nums2.size(); i++) {
            if (st.find(h2.rangeHash(i - mid + 1, i)) != st.end()) {
                return true;
            }
        }
        
        return false;
    }
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        Hash h1(nums1);
        Hash h2(nums2);
        
        int l = 1, h = min(nums1.size(), nums2.size());
        while (l <= h) {
            int mid = l + (h - l) / 2;
            
            if (check(nums1, nums2, mid, h1, h2)) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
        
        return l - 1;
    }
};
