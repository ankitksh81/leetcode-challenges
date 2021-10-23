/*
    Sort characters by frequency
    https://leetcode.com/problems/sort-characters-by-frequency/
*/

// Solution 1:

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char c: s) {
            mp[c]++;
        }
        sort(s.begin(), s.end(), [&](char a, char b){
            if(mp[a] == mp[b]) {
                return a < b;
            }
            return mp[a] > mp[b];
        });
        return s;
    }
};

// Solution 2:

class Solution {
public:
    string frequencySort(string s) {
        int size = 'z'-'0'+ 1;
        pair<char, int> freq[size];
        for(int i = 0; i < size; i++){
            pair<char, int> p('0'+ i, 0);
            freq[i] = p;
        }
    
        for(char c: s){
            freq[c - '0'].second++;
        }
        
        sort(freq, freq + size, [](pair<char, int> a, pair<char, int> b){
                return a.second > b.second;
            });
        
        string ret(s.size(), ' ');
        int idx = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < freq[i].second; j++){
                ret[idx] = freq[i].first;
                idx++;
            }
        }
        
        return ret;
    }
};