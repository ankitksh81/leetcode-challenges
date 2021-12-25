/*
    Basic calculator II
    https://leetcode.com/problems/basic-calculator-ii/
*/

// Solution 1: Using stack

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if(n == 0) {
            return 0;
        }
        stack<int> st;
        int curNum = 0;
        char op = '+';
        
        for(int i = 0; i < n; i++) {
            char cur = s[i];
            if(isdigit(cur)) {
                curNum = (curNum * 10) + (cur - '0');
            }
            if(!isdigit(cur) && cur != ' ' || i == n - 1) {
                if(op == '-') {
                    st.push(-curNum);
                } else if(op == '+') {
                    st.push(curNum);
                } else if(op == '*') {
                    int ele = st.top();
                    st.pop();
                    st.push(ele * curNum);
                } else if(op == '/') {
                    int ele = st.top();
                    st.pop();
                    st.push(ele / curNum);
                }
                op = cur;
                curNum = 0;
            }
        }
        
        int res = 0;
        while(st.size() != 0) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

// Solution 2: Constant space

class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
};