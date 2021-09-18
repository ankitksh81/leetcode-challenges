// Problem link: https://leetcode.com/explore/challenge/card/september-leetcoding-challenge-2021/638/week-3-september-15th-september-21st/3979/


// Solution 1:

class Solution {
public:
    void dfs(string& num, string& expr, int numPos, int exprLen,
             int64_t left, int64_t right, int target, vector<string>& result) {
        if (numPos == num.size()) {
            if (left + right == target) {
                result.push_back(expr.substr(0, exprLen));
            }
            return;
        }
        
        int64_t digit = 0;
        for (int i = numPos; i < num.size(); i++) {
            if (i > numPos && digit == 0) {
                break;
            }
            
            digit = digit * 10 + (num[i] - '0');
            expr[exprLen + i - numPos + 1] = num[i];
            
            expr[exprLen] = '+';
            dfs(num, expr, i + 1, exprLen + i - numPos + 2, left + right, digit, target, result);
            expr[exprLen] = '-';
            dfs(num, expr, i + 1, exprLen + i - numPos + 2, left + right, -digit, target, result);
            expr[exprLen] = '*';
            dfs(num, expr, i + 1, exprLen + i - numPos + 2, left, right * digit, target, result);
        }
    }
    
    vector<string> addOperators(string num, int target) {
        string expr(2 * num.size(), ' ');
        
        int64_t digit = 0;
        vector<string> result;
        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && digit == 0) {
                break;
            }
            
            digit = digit * 10 + (num[i] - '0');
            expr[i] = num[i];
            dfs(num, expr, i + 1, i + 1, 0, digit, target, result);
        }
        return result;
    }
};


// Solution 2:

class Solution {
public:
    void helper(vector<string>& ans, string nums, string cur_str, long long last, long long cur_val, int target) {
        if(nums.length() == 0) {
            if(cur_val == target) {
                ans.push_back(cur_str);
            }
            return;
        }

        for(int i = 1; i <= nums.length(); i++) {
            string cur_num = nums.substr(0, i);
            if(cur_num.length() > 1 && cur_num[0] == '0') {
                return;
            }

            string next_num = nums.substr(i);

            if(cur_str.length() > 0) {
                helper(ans, next_num, cur_str + "+" + cur_num, stoll(cur_num), cur_val + stoll(cur_num), target);
                helper(ans, next_num, cur_str + "-" + cur_num, -stoll(cur_num), cur_val - stoll(cur_num), target);
                helper(ans, next_num, cur_str + "*" + cur_num, last * stoll(cur_num), (cur_val - last) + (last * stoll(cur_num)), target);
            }
            else {
                helper(ans, next_num, cur_num, stoll(cur_num), stoll(cur_num), target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(ans, num, "", 0, 0, target);
        return ans;
    }
};