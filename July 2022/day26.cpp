/*
	Lowest Common Ancestor of a Binary Tree
	https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

// Solution: Recursion

class Solution {
public:
    int solve(TreeNode* root, int req, TreeNode* p, TreeNode* q, TreeNode* &lca) {
        if(!root) {
            return 0;
        }
        
        int left = solve(root->left, req, p, q, lca);
        int right = solve(root->right, req, p, q, lca);
        
        int total = left + right;
        if(root == p || root == q) {
            total++;
        }
        
        if(total == req && !lca) {
            lca = root;
        }
        
        return total;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = nullptr;
        solve(root, 2, p, q, lca);
        return lca;
    }
};