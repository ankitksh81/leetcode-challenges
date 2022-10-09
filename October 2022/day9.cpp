/*
	Two Sum IV - Input is a BST
	https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
*/

// Solution: Recursion + Hashmap

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
    unordered_map<int, bool> mp;
public:
    bool findTargetSum(TreeNode *root, int sum) {
        if (!root) return false;

        if (mp.find(sum - root->val) != mp.end()) {
            return true;
        }

        mp[root->val] = true;
        return findTargetSum(root->left, sum) || findTargetSum(root->right, sum);
    }

    bool findTarget(TreeNode* root, int k) {
        return findTargetSum(root, k);
    }
};