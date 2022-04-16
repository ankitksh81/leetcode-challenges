/*
	Convert BST to Greater Tree
	https://leetcode.com/problems/convert-bst-to-greater-tree/
*/

// Solution: Recursion

class Solution {
public:
    void convert(TreeNode* root, int &sum) {
        if(!root) {
            return;
        }
        
        convert(root->right, sum);
        sum += root->val;
        root->val = sum;
        convert(root->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if(!root) {
            return root;
        }
        
        int sum = 0;
        convert(root, sum);
        return root;
    }
};

// Solution 2: Using Stack

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root) {
            return root;
        }
        stack<TreeNode*> nodes;
        TreeNode* cur = root;
        int sum = 0;
        
        // push all right nodes
        while(cur) {
            nodes.push(cur);
            cur = cur->right;
        }
        
        // update values of nodes
        while(!nodes.empty()) {
            cur = nodes.top();
            nodes.pop();
            
            sum += cur->val;
            cur->val = sum;
            
            if(cur->left) {
                cur = cur->left;
                while(cur) {
                    nodes.push(cur);
                    cur = cur->right;
                }
            }
        }
        
        return root;
    }
};