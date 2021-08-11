// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3877/


// Solution 1:

class Solution {
public:
	bool canReorderDoubled(vector<int>& A) {
		map<int, int> m;
		int n = A.size();
		for(int i = 0; i < n; i++){
			m[A[i]]++;
		}
		int cnt = A.size();
		auto it = m.begin();

		while(it != m.end()) {
			if(m[it->first] > 0) {
				if(it->first != 0 && m[it->first * 2] > 0) {
					int x = min(m[it->first], m[it->first * 2]);
					cnt -= (2 * x);
					m[it->first * 2] -= x;
					m[it->first] -= x;
				}
				else if(it->first == 0) {
					cnt -= m[it->first];
					m[it->first] = 0;
				}
			}
			it++;
		}
		return !cnt;
	}
};

// Solution 2:

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int counter[100001] = {0};
        int counter2[100001] = {0};
        for(int v: arr) {
            if(v >= 0) {
                counter[v]++;
            }
            else {
                counter2[-v]++;
            }
        }
        if(counter[0] % 2 == 1) {
            return false;
        }
        for(int i = 1; i <= 50000; i++)  {
            if(counter[i * 2] < counter[i] || counter2[i * 2] < counter2[i]) {
                return false;
            }
            counter[i * 2] -= counter[i];
            counter2[i * 2] -= counter2[i];
        }
        for(int i = 50001; i <= 100000; i++) {
            if(counter[i] || counter2[i]) {
                return false;
            }
        }
        return true;
    }
};