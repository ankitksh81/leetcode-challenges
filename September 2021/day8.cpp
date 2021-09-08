// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3968/


// Solution 1:

class Solution {
public:
	void shiftChar(char &c, long shift) {
		if(shift > (26 - (c - 'a' + 1))) {
			shift = shift - (26 - (c - 'a' + 1));
			shift--;
			c = 'a';
			shift %= 26;
		}
		c = c + shift;
	}
	
	string shiftingLetters(string s, vector<int>& shifts) {
		string ans = s;
		int n = shifts.size();
		
		vector<long> pref(n+1);
		pref[0] = 0;
		for(int i = 1; i <= n; i++) {
			pref[i] = pref[i-1] + shifts[i-1];
		}
		
		for(int i = 0; i < n; i++) {
			long shift = pref[n] - pref[i];
			shiftChar(ans[i], shift);
		}
		return ans;
	}
};


// Solution 2:

class Solution {
public:
	string shiftingLetters(string s, vector<int>& shifts) {
		int n = shifts.size();
		
		for(int i = n - 2; i >= 0; i --) {
			shifts[i] = (shifts[i] + shifts[i+1]) % 26;
		}
		for(int i = 0; i < n; i ++) {
			s[i] = (s[i] - 'a' + shifts[i]) % 26 +'a';
		}
		
		return s;
	}
};