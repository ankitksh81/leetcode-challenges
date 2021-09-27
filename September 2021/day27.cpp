// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/639/week-4-september-22nd-september-28th/3989/


// Solution:

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        int ans = 0;
        unordered_set<string> s;
        
        for(string email: emails) {
            string local = "", domain = "";
            bool isAt = false;
            int plus = 0;
            
            for(char c: email) {
                if(!isAt && plus % 2 == 0 && c != '.') {
                    if(c == '@') {
                        isAt = true;
                        continue;
                    }
                    else if(c == '+') {
                        plus++;
                        continue;
                    }
                    local += c;
                }
                else if(c == '@') {
                    isAt = true;
                    continue;
                }
                if(isAt) {
                    domain += c;
                }
            }
            
            string res = local + "@" + domain;
            s.insert(res);
        }
        return s.size();
    }
};