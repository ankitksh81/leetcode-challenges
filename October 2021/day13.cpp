/*
    Construct Binary Search Tree from preorder traversal
    https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
    int idx = 0;
    TreeNode* buildBST(int parent, vector<int>& preorder) {
        if(idx == preorder.size() || preorder[idx] > parent) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = buildBST(root->val, preorder);
        root->right = buildBST(parent, preorder);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(INT_MAX, preorder);
    }
};


// Solution 2:

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode *p, *t, *root = nullptr;
        stack<TreeNode*> st;
        int i = 0;
        root = new TreeNode;
        root->val = pre[i++];
        root->left = root->right = nullptr;
        p = root;

        while(i < pre.size()) {
            if(pre[i] < p->val) {
                t = new TreeNode;
                t->val = pre[i++];
                t->left=  t->right = nullptr;
                p->left = t;
                st.push(p);
                p = t;
            }
            else {
                if(!st.empty()) {
                    if(pre[i] > p->val && pre[i] < st.top()->val) {
                        t = new TreeNode;
                        t->val = pre[i++];
                        t->left = t->right = nullptr;
                        p->right = t;
                        p = t;
                    }
                    else {
                        p = st.top();
                        st.pop();
                    }
                }
                else {
                    if(pre[i] > p->val) {
                        t = new TreeNode;
                        t->val = pre[i++];
                        t->left = t->right = nullptr;
                        p->right = t;
                        p = t;
                    }
                }
            }
        }
        return root;
    }
};