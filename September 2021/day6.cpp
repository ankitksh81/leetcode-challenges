// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/636/week-1-september-1st-september-7th/3965/


// Solution 1:

class Solution {
public:
	char slowestKey(vector<int>& releaseTimes, string keysPressed) {
		int n = keysPressed.length();
		char ans = keysPressed[0];
		vector<int> pref(n);
		pref[0] = releaseTimes[0];
		
		for(int i = 1; i < n; i++) {
			pref[i] = releaseTimes[i] - releaseTimes[i-1];
		}
		
		int mx = pref[0];
		for(int i = 1; i < n; i++) {
			if(pref[i] > mx) {
				mx = pref[i];
				ans = keysPressed[i];
			}
			else if(pref[i] == mx) {
				ans = max(ans, keysPressed[i]);
			}
		}
		return ans;
	}
};

// Solution 2:

class Solution {
public:
	char slowestKey(vector<int>& releaseTimes, string keysPressed) {
		char res = keysPressed[0];
		int max = releaseTimes[0];
		for(int i = 0; i < releaseTimes.size() - 1; i++) {
			int tmp = releaseTimes[i+1] - releaseTimes[i];
			if(tmp > max) {
				max = tmp;
				res = keysPressed[i+1];
			}
			else if(tmp == max && keysPressed[i+1] > res) {
				res = keysPressed[i+1];
			}
		}
		return res;
	}
};