/*
	Binary Tree Right Side View
	https://leetcode.com/problems/binary-tree-right-side-view/
*/

// Solution 1: Preorder Traversal

class Solution {
public:
    void getRightSideView(TreeNode* root, vector<int>& res, int lvl) {
        if (!root) return;
        
        if (res.size() <= lvl) {
            res.push_back(-1);
        }
        res[lvl] = root->val;
        getRightSideView(root->left, res, lvl + 1);
        getRightSideView(root->right, res, lvl + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        getRightSideView(root, result, 0);
        return result;
    }
};


// Solution 2: Level Order Traversal

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            ans.push_back(q.back()->val);
            int q_size = q.size();
            for(int i = 0; i < q_size; i++) {
                TreeNode* cur_node = q.front();
                q.pop();

                if(cur_node->left != nullptr) {
                    q.push(cur_node->left);
                }
                if(cur_node->right != nullptr) {
                    q.push(cur_node->right);
                }
            }
        }

        return ans;
    }
};