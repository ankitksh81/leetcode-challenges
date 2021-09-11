// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/637/week-2-september-8th-september-14th/3971/


// Solution:

class Solution {
public:
    bool isdigit(char s) {
        if(s >= '0' && s <= '9') {
            return true;
        }
        return false;
    }
    
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        int sum = 0;
        int sign = 1;
        int val = 0;
        for(int i = 0; i < n; i++) {
            while(i < n && isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            sum += (val * sign);
            val = 0;
            
            if(s[i] == '-')
                sign = -1;
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '(') {
                st.push(sum);
                sum = 0;
                st.push(sign);
                sign = 1;
            }
            else if(s[i] == ')') {
                sum = sum * st.top();
                st.pop();
                sum += st.top();
                st.pop();
            }
        }
        return sum;
    }
};