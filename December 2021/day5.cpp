/*
    House robber III
    https://leetcode.com/problems/house-robber-iii/
*/

// Solution 1: Hashmap

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
    unordered_map<TreeNode*, int> um;
    int rob(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        if(um.find(root) != um.end()) {
            return um[root];
        }
        
        int total = 0;
        
        if(root->left) {
            total += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right) {
            total += rob(root->right->left) + rob(root->right->right);
        }
        
        return um[root] = max(root->val + total, rob(root->left) + 
            rob(root->right));
    }
};

// Solution 2: Pairs

class Solution {
public:
    pair<int, int> solve(TreeNode* root) {
        if(root == nullptr) {
            return {0,0};
        }
        
        pair<int, int> p1 = solve(root->left);
        pair<int, int> p2 = solve(root->right);
        
        int rob = root->val;
        rob += p1.second + p2.second;
        int notrob = max(p1.first, p1.second) + max(p2.first, p2.second);
        
        return {rob, notrob};
    };
    
    int rob(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};