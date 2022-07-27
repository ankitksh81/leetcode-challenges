/*
	Flatten Binary Tree to Linked List
	https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/

// Solution: Iterative using Prev Pointer

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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        TreeNode* cur = root, *prev = nullptr;
        while (cur) {
            if (cur->left) {
                prev = cur->left;
                
                while (prev->right) {
                    prev = prev->right;
                }
                
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};