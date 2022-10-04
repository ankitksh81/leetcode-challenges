/*
        Path Sum
        https://leetcode.com/problems/path-sum/description/
*/

// Solution: Recursion

class Solution {
public:
    bool findPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        if (!root->left && !root->right && targetSum - root->val == 0) return true;

        if (!root->left && !root->right && targetSum - root->val != 0) return false;

        return findPathSum(root->left, targetSum - root->val) || findPathSum(root->right, targetSum - root->val);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return findPathSum(root, targetSum);
    }
};
