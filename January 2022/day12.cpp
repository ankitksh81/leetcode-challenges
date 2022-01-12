/*
	Insert into a Binary Search Tree
	https://leetcode.com/problems/insert-into-a-binary-search-tree/
*/

// Solution 1: Recursion

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return new TreeNode(val);
        }
        if(val > root->val) {
            root->right = insertIntoBST(root->right, val);
        }
        else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};

// Solution 2: Iterative

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* cur = root;
        while(cur) {
            if(cur->val > val && cur->left) {
                cur = cur->left;
            }
            else if(cur->val < val && cur->right){
                cur = cur->right;
            }
            else {
                break;
            }
        }
        
        if(val > cur->val) {
            cur->right = new TreeNode(val);
        }
        else {
            cur->left = new TreeNode(val);
        }
        
        return root;
    }
};