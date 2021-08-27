// Problem link: https: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3921/


// Solution 1:

class Solution {
public:
	int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> m;
        for(auto &s: strs) {
        	for(int i = 0; i < (1 << s.size()); i++) {
        		string t;

        		for(int j = 0; j < s.size(); j++) {
        			if((i >> j) & 1) {
        				t += s[j];
        			}
        		}
        		m[t]++;
        	}
        }
        int ans = -1;

        for(auto &a: m) {
        	if(a.second == 1) {
        		ans = max(ans, (int)a.first.size());
        	}
        }
        return ans;
    }
};

// Solution 2:

class Solution {
public:
	bool check(string a, string b) {
		int A = a.size(), B = b.size();

		while(A > 0 && B > 0) {
			int i = a.size() - A;
			int j = b.size() - B;

			if(a[i] == b[j]) {
				A--;
			}
			B--;
		}
		return A == 0;
	}

	int findLUSlength(vector<string>& strs) {
		int maxLen = -1;
		for(int i = 0; i < strs.size(); i++) {
			int curLen = strs[i].length();
			bool flag = true;

			for(int j = 0; j < strs.size(); j++) {
				if(i != j && check(strs[i], strs[j])) {
					flag = false;
					break;
				}
			}

			if(flag) {
				maxLen = max(maxLen, curLen);
			}
		}
		return maxLen;
	}
};