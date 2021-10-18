/*
    Cousins in binary tree
    https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            bool isX = false;
            bool isY = false;
            
            for(int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->val == x) {
                    isX = true;
                }
                if(node->val == y) {
                    isY = true;
                }
                
                if(node->left && node->right) {
                    if((node->left->val == x && node->right->val == y) || 
                       (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) { 
                    q.push(node->right);
                }
            }
            if(isX && isY) {
                return true;
            }
        }
        return false;
    }
};