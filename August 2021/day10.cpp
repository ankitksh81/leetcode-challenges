// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3876/


// Solution 1:

class Solution {
public:
    int minFlipsMonoIncr(string s) {
	    int n = s.length();
	    int flip = 0, one_count = 0;
        
	    for(int i = 0; i < n; i++) {
		    if(s[i] == '0') {
			    if(one_count != 0){
				    flip++;
			    }
		    }
		    else {
			    one_count++;
		    }
		    flip = min(flip, one_count);
	    }
	    return flip;
    }
};


// Solution 2:

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count0 = 0, count1 = 0;
        for(int i = 0; i < s.length(); i++){
            count0 += (s[i] == '1');
            count1 = min(count0, count1 + (s[i] == '0'));
        }
        return count1;
    }
};