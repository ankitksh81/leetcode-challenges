// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/614/week-2-august-8th-august-14th/3875/


// Solution 1:

class Solution {
public:
    string addStrings(string num1, string num2) {
        int it1 = num1.size() - 1 , it2 = num2.size() - 1;
        int rem = 0 ;
        string ans = "" ;
        while(it1 >= 0 || it2 >= 0)
        {
            if(it1 >= 0)
            {
                rem += num1[it1--] - '0' ;
            }
            if(it2 >= 0)
            {
                rem += num2[it2--] - '0' ;
            }
            ans = to_string(rem%10) + ans ;
            rem /= 10 ;
        }
        return rem ? "1"+ans : ans ;
    }
};

// Solution 2:

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        string res = "";
        int i1 = n1 - 1, i2 = n2 - 1;
        int carry = 0;
        
        while(i1 >= 0 || i2 >= 0) {
            int sum = carry;
            sum += i1 >= 0 ? num1[i1--] - '0' : 0;
            sum += i2 >= 0 ? num2[i2--] - '0' : 0;
            
            if(sum > 9) {
                sum -= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            res.push_back(sum + '0');
        }
        if(carry == 1) {
            res.push_back(carry + '0');            
        }
        while(!res.empty() && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};