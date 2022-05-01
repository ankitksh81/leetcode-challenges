/*
	Backspace String Compare
	https://leetcode.com/problems/backspace-string-compare/
*/

// Solution 1: Stack

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, st;
        for(char c: s){
            if(c == '#' && !ss.empty()){
                ss.pop();
            }
            else if(c == '#' && ss.empty()){
                continue;
            }
            else{
                ss.push(c);
            }
        }
        for(char c: t){
            if(c == '#' && !st.empty()){
                st.pop();
            }
            else if(c == '#' && st.empty()){
                continue;
            }
            else{
                st.push(c);
            }
        }
        string a = "", b = "";
        while(!ss.empty()){
            char c = ss.top();
            a += c;
            ss.pop();
        }
        while(!st.empty()){
            char c = st.top();
            b += c;
            st.pop();
        }
        return (a == b ? true : false);
    }
};

// Solution 2: Two Pointers

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1, j = t.length()-1;
        int skipS = 0, skipT = 0;
        
        while(i >= 0 || j >= 0) {
            while(i >= 0) {
                if(s[i] == '#') {
                    skipS++;
                    i--;
                }
                else if(skipS > 0) {
                    skipS--;
                    i--;
                }
                else {
                    break;
                }
            }
            while(j >= 0) {
                if(t[j] == '#') {
                    skipT++;
                    j--;
                }
                else if(skipT > 0) {
                    skipT--;
                    j--;
                }
                else {
                    break;
                }
            }
            
            if(i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            
            if((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};