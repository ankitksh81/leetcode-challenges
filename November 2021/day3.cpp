/*
    Sum root to leaf numbers
    https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/

// Solution 1:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root, int num=0) {
        return root->left == root->right ? num * 10 + root->val :
            ((root->left ? sumNumbers(root->left, num * 10 + root->val) : 0) + 
            (root->right ? sumNumbers(root->right, num * 10 + root->val) : 0));
    }
};

// Solution 2:

class Solution {
public:
    int ans = 0;
    int strtoint(string s) {
        return stoi(s);
    }
    
    void RtoLHelper(TreeNode *root, string s) {
        if(root == nullptr) {
            return;
        }
        s = s + to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            ans += (strtoint(s));
            return;
        }
        RtoLHelper(root->left, s);
        RtoLHelper(root->right, s);
    }
    
    int sumNumbers(TreeNode* root) {
        RtoLHelper(root, "");
        return ans;
    }
};