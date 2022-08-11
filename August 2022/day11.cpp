/*
	Validate Binary Search Tree
	https://leetcode.com/problems/validate-binary-search-tree/
*/

// Solution: Recursion

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
    bool validateBST(TreeNode* root, TreeNode* &prev) {
        if (!root) return true;
        if (!validateBST(root->left, prev)) {
            return false;
        }
        
        if (prev && prev->val >= root->val) {
            return false;
        }
        
        prev = root;
        return validateBST(root->right, prev);
    }
    
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return validateBST(root, prev);
    }
};