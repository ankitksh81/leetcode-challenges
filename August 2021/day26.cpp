// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3920/


// Solution 1:

class Solution {
public:
    bool isValidSerialization(string s) {
        int cur = 1;
        string temp = "";
        s.push_back(',');
        vector<string> v;
        for(auto c: s) {
            if(c == ',') {
                v.push_back(temp);
                temp.clear();
            }
            else {
                temp.push_back(c);
            }
        }
        for(auto str: v) {
            cur--;
            if(cur < 0) {
                return false;
            }
            if(str != "#") {
                cur += 2;
            }
        }
        return cur == 0;
    }
};


// Solution 2:

class Solution {
public:
    bool isValidSerialization(string pre) {
        stack<int> s;
        if(pre.length() == 1 && pre[0] == '#') {
            return true;
        }
        string num = "";
        for(int i = 0; i < pre.length(); i++) {
            if(pre[i] == ',') {
                continue;
            }
            if(s.empty() && i > 0) {
                return false;
            }
            if(pre[i] == '#') {
                if(s.empty()) {
                    return false;
                }
                s.top()--;
                while(!s.empty() && s.top() == 0) {
                    s.pop();
                    if(!s.empty()) {
                        s.top()--;
                    }
                    if(!s.empty() && s.top() < 0) {
                        return false;
                    }
                }
            }
            else {
                int j = i;
                while(j < pre.size() && pre[j] != ',') {
                    j++;
                }
                i = j-1;
                s.push(2);
            } 
        }
        if(s.size() > 0) {
            return false;
        }
        return true;
    }
};