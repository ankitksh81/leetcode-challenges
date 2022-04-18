/*
	Kth  Smallest Element in a BST
	https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    vector<int> nodes;
public:
    void findInorder(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        findInorder(root->left);
        nodes.push_back(root->val);
        findInorder(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        findInorder(root);
        return nodes[k-1];
    }
};

// Solution 2: Stack

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        
        TreeNode* cur = root;
        while(cur) {
            st.push(cur);
            cur = cur->left;
        }
        
        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            if(--k == 0) {
                return node->val;
            }
            
            if(node->right) {
                node = node->right;
                while(node) {
                    st.push(node);
                    node = node->left;
                }
            }
        }
        
        return -1;
    }
};