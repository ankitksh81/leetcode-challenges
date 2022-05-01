/*
	Find Permutation
	https://leetcode.com/problems/find-permutation/
*/

// Solution 1: Stack

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> result(s.length() + 1);
        stack<int> st;
        int j = 0;
        
        for(int i = 1; i <= s.length(); i++) {
            if(s[i-1] == 'I') {
                st.push(i);
                while(!st.empty()) {
                    result[j++] = st.top();
                    st.pop();
                }
            }
            else {
                st.push(i);
            }
        }
        
        st.push(s.length() + 1);
        while(!st.empty()) {
            result[j++] = st.top();
            st.pop();
        }
        
        return result;
    }
};

// Solution 2: Two Pointers

class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.length() + 1);
        res[0] = 1;
        int i = 1;
        
        while(i <= s.length()) {
            res[i] = i + 1;
            int j = i;
            if(s[i-1] == 'D') {
                while(i <= s.length() && s[i-1] == 'D') {
                    i++;
                }
                for(int k = j-1, c = i; k <= i - 1; k++, c--) {
                    res[k] = c;
                }
            }
            else {
                i++;
            }
        }
        
        return res;
    }
};