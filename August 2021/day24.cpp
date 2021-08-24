// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/616/week-4-august-22nd-august-28th/3917/


// Solution 1:

class Solution {
public:
    pair<int, int> solve(const string &a) {
        int plus = find(a.begin(), a.end(), '+') - a.begin();
        int i = find(a.begin(), a.end(), 'i') - a.begin();
        int real = stoi(a.substr(0, plus));
        int img = stoi(a.substr(plus + 1, i - plus));
        return {real, img};
    }
    
    string complexNumberMultiply(string a, string b) {
        pair<int, int> av = solve(a);
        pair<int, int> bv = solve(b);
        int real = av.first * bv.first - av.second * bv.second;
        int img = av.first * bv.second + av.second * bv.first;
        
        return to_string(real) + "+" + to_string(img) + "i";
    }
};


// Solution 2:

class Solution {
public:
    string complexNumberMultiply(string x, string y) {
        int a, b, c, d;
        sscanf(x.c_str(), "%d+%di", &a, &b);
        sscanf(y.c_str(), "%d+%di", &c, &d);
        return to_string(a * c - b * d) + "+" + to_string(a * d + b * c) + "i";
    }
};