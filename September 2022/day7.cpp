/*
	Construct String from Binary Tree
	https://leetcode.com/problems/construct-string-from-binary-tree/
*/

// Solution: Recursion

class Solution {
public:
    void solve(TreeNode* root, string &s) {
        if(root == nullptr) {
            return;
        }
        string num = to_string(root->val);
        s += num;
        if(!root->left && !root->right) {
            return;
        }
        if(root->left && !root->right) {
            s += "(";
            solve(root->left, s);
            s += ")";
        }
        else if(!root->left && root->right) {
            s += "()(";
            solve(root->right, s);
            s += ")";
        }
        else {
            s += "(";
            solve(root->left, s);
            s += ")(";
            solve(root->right, s);
            s += ")";
        }
    }
    
    string tree2str(TreeNode* root) {
        string s = "";
        solve(root, s);
        return s;
    }
};