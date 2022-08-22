/*
	Binary Tree Longest Consecutive Sequence II
	https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/
*/

// Solution: Recursion (DFS)

class Solution {
public:
    vector<int> solve(TreeNode* root, int &ans) {
        if (!root) {
            return {0, 0};
        }
        
        int inc = 1, dec = 1;
        if (root->left) {
            vector<int> left = solve(root->left, ans);
            if (root->val == root->left->val + 1) {
                dec = left[1] + 1;
            }
            else if (root->val == root->left->val - 1) {
                inc = left[0] + 1;
            }
        }
        
        if (root->right) {
            vector<int> right = solve(root->right, ans);
            if (root->val == root->right->val + 1) {
                dec = max(dec, right[1] + 1);
            }
            if (root->val == root->right->val - 1) {
                inc = max(inc, right[0] + 1);
            }
        }
        
        ans = max(ans, dec + inc - 1);
        return {inc, dec};
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};