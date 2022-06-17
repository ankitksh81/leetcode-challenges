/*
	Binary Tree Cameras
	https://leetcode.com/problems/binary-tree-cameras/
*/

// Solution: Greedy + DFS

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
    void dfs(TreeNode* root, TreeNode* par, unordered_set<TreeNode*>& s, int &res) {
        if (root != nullptr) {
            dfs(root->left, root, s, res);
            dfs(root->right, root, s, res);
            
            if (par == nullptr && !s.count(root) 
                || !s.count(root->left) || !s.count(root->right)) {
                res++;
                s.insert(root);
                s.insert(par);
                s.insert(root->left);
                s.insert(root->right);
            }
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> s;
        s.insert(nullptr);
        
        int res = 0;
        dfs(root, nullptr, s, res);
        
        return res;
    }
};