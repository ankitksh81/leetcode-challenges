/*
    Longest duplicate substring
    https://leetcode.com/problems/longest-duplicate-substring/
*/

// Solution 1:

class Solution {
private:
    vector<long long> pow;
    const int prime = (int)(1e9+9);
    const int p = 31;
public:
    // Rabin karp for finding the required substring
    inline string rabin_karp(string &s, int &k) {
        if(k == 0) {
            return "";
        }
        long long hash = 0;
        unordered_map<long long, vector<int>> mp;
        for(int i = k - 1; i >= 0; i--) {
            hash = (hash % prime + (pow[k - 1 - i] * (s[i] - 'a' + 1)) % prime) % prime;
        }
        
        int i = 0, j = k-1;
        mp[hash] = vector<int>(1, 0);
        bool flag = 0;
        while(j < s.length()) {
            hash = (hash % prime - ((pow[k - 1] * (s[i] - 'a' + 1)) % prime) + prime) % prime;
            hash = (hash % prime * p % prime) % prime;
            i++;
            j++;
            
            if(j < s.length()) {
                hash = (hash % prime + ((pow[0] * (s[j] - 'a' + 1)) % prime)) % prime;
                if(mp.find(hash) != mp.end()) {
                    for(auto idx: mp[hash]) {
                        if(strcmp((s.substr(idx, k)).data(), s.substr(i, k).data()) == 0) {
                            return s.substr(idx, k);
                        }
                    }
                    mp[hash].push_back(i);
                }
                else {
                    mp[hash] = vector<int>(1, i);
                }
            }
        }
        return "";
    }
    
    string longestDupSubstring(string s) {
        int n = s.length();
        pow.resize(n + 1);
        pow[0] = 1;
        
        for(int i = 1; i <= n; i++) {
            pow[i] = (pow[i-1] * p) % prime;
        }
        
        int l = 0, r = n;
        string res = "";
        // Binary search on the length of duplicate string
        while(l <= r) {
            int mid = l + (r - l) / 2;
            string valid = rabin_karp(s, mid);
            
            if(valid.length() > 0) {
                if(valid.length() > res.length()) {
                    res = valid;
                }
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return res;
    }
};

// Solution 2:

class Solution {
public:
    string longestDupSubstring(string s) {
        auto check = [&](int size) {
            if (size==0) {
                return make_pair(true, 0);
            }
            
            vector<int> hashMap[433];
            int M = 433, hash = 0, f = 1;
            for(int i = 0; i < s.size(); i++) {
                if(i < size - 1) {
                    f = (f * 31) % M;
                }
                
                if(i >= size) {
                    hash -= (s[i - size] - 'a') * f;
                    hash = (M + hash % M) % M;
                }
                
                hash = ((hash * 31) % M + (s[i] - 'a')) % M;

                if(i < size - 1) {
                    continue; // size th do this
                }
                if(hashMap[hash].size() == 0) {
                    hashMap[hash].push_back(i);
                }
                else {
                    auto &entry = hashMap[hash];
                    for(int index: entry) {
                        int tempi = i;
                        int tempsize = size;
                        while(tempsize > 0 && s[index] == s[tempi]) {
                            index--;
                            tempi--;
                            tempsize--;
                        }
                        if (tempsize==0) {
                            return make_pair(true, i);
                        }
                    }
                    entry.push_back(i);
                }
            }
            return make_pair(false, -1);
        };
        
        // Binary search on the length of the duplicate string
        int lo = 0, hi = s.size() - 1, index;
        bool res;
        while(lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            tie(res, index) = check(mid);
            if(res == false) {
                hi = mid - 1;
            }
            else lo = mid;
        }
        tie(res, index) = check(lo);
        return s.substr(index - (lo) + 1, lo);
    }
};