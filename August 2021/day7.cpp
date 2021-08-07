// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3872/


// Solution 1:

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<int> cut(len, 0);
        
        for(int i = 1; i < len; i++){
            cut[i] = i;
        }
        for(int i = 1; i < len; i++){
            for(int j = 0; i-j >= 0 && i+j < len && s[i-j] == s[i+j]; j++){
                cut[i+j] = (i-j == 0 ? 0 : min(cut[i+j], cut[i-j-1]+1));
            }
            for(int j = 0; i-j-1 >= 0 && i+j < len && s[i-j-1] == s[i+j]; j++){
                cut[i+j] = i-j-1 == 0 ? 0 : min(cut[i+j], cut[i-j-2]+1);
            }
        }
        return cut[len-1];
    }
};



// Solution 2:

class Solution {
public:
    int minCut(string s) {
        if(isPal(s, 0, s.length()-1))
        	return 0;
        for(int i = 0; i < s.length(); ++i){
            if(isPal(s, 0, i) && isPal(s, i+1, s.length()-1)){
                return 1;
            }
        }

        vector<int> dp;
        dp.push_back(-1);
        for(int i = 0; i < s.length(); ++i){
            dp.push_back(i);
        }
        
        int idx = 0;
        for(int i = 0; i < s.length(); ++i){
            idx = 0;
            while(i - idx >=0 && i + idx < s.length() && s[i-idx] == s[i+idx]){
                dp[i + idx + 1] = min(dp[i + idx + 1], dp[i - idx] + 1);
                ++idx;
            }
            idx = 0;
            while(i - idx >= 0 && i + idx + 1 < s.length() && s[i - idx] == s[i + idx + 1]){
                dp[i + idx + 2] = min(dp[i + idx + 2], dp[i - idx] + 1);
                ++idx;
            }

        }
        return dp.back();
    }
    
    bool isPal(const string& s, int start, int end){
        while (start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};