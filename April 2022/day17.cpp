/*
	Increasing Order Search Tree
	https://leetcode.com/problems/increasing-order-search-tree/
*/

// Solution 1: Recursion

class Solution {
public:
    void solve(TreeNode* root, TreeNode* &cur) {
        if(!root) {
            return;
        }
        
        solve(root->left, cur);
        root->left = nullptr;
        cur->right = root;
        cur = cur->right;
        solve(root->right, cur);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        TreeNode* cur = dummy;
        
        solve(root, cur);
        return dummy->right;
    }
};

// Solution 2: Stack

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) {
            return root;
        }
        
        TreeNode* ans, *cur = root;
        stack<TreeNode*> st;
        
        while(cur) {
            st.push(cur);
            cur = cur->left;
        }
        
        ans = st.top();
        while(!st.empty()) {
            auto node = st.top();
            st.pop();
            
            if(node->right) {
                auto tmp = node->right;
                while(tmp) {
                    st.push(tmp);
                    tmp = tmp->left;
                }
            }
            
            node->left = nullptr;
            node->right = st.empty() ? nullptr : st.top();
        }
        
        return ans;
    }
};