// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3887/


// Solution 1:

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        vector<string> temp = strs;
        
        unordered_map<string, vector<string>> umap;
        
        for(int i = 0; i < n; i++) {
            string s = temp[i];
            sort(temp[i].begin(), temp[i].end());
            umap[temp[i]].push_back(s);
        }
        
        for(auto it: umap){
            ans.push_back(it.second);
        }
        return ans;
    }
};


// Solution 2:

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(auto s: strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(auto it: umap){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};