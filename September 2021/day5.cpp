// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3964/


// Solution:

class Solution {
public:
	string orderlyQueue(string s, int k) {
		int n = s.length();
		if(k == 1) {
			string ans = s;
			for(int i = 0; i < n; i++) {
				ans = min(ans, s.substr(i) + s.substr(0,i));
			}
			
			return ans;
		}
		
		sort(s.begin(), s.end());
		return s;
	}
};

