/*
	Binary Tree Inorder Traversal
	https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> res;
public:
    void findInorderTraversal(TreeNode* root) {
        if (!root) return;
        
        findInorderTraversal(root->left);
        res.push_back(root->val);
        findInorderTraversal(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        findInorderTraversal(root);
        return res;
    }
};