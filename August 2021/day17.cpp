// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3899/


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
    int dfs(TreeNode* root, int curr_max, int &good_nodes) {
        if(root->val >= curr_max) {
            good_nodes++;
        }
        
        if(root->left) {
            dfs(root->left, max(root->val, curr_max), good_nodes);
        }
        
        if(root->right) {
            dfs(root->right, max(root->val ,curr_max), good_nodes);
        }
        
        return good_nodes;
    }
    
    int goodNodes(TreeNode* root) {
        int good_nodes = 0;
        if(root == nullptr){
            return 0;
        }
        return dfs(root, INT_MIN, good_nodes);
    }
};


// Solution 2:

class Solution {
public:
    int goodNodes(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int result = 0;
        queue<pair<TreeNode*, int>> next;
        next.push({root, root->val});
        
        while(!next.empty()) {
            auto curr = next.front();
            TreeNode *curr_node = curr.first;
            int Max = curr.second;
            
            if(curr_node -> right == nullptr && curr_node -> left == nullptr) {
                next.pop();
                if(curr_node -> val >= Max) {
                    result++;
                }
            }
            else if(curr_node->right != nullptr) {
                next.push({curr_node->right, max(Max, curr_node->val)});
                curr_node->right = nullptr;
            }
            else if(curr_node->left != nullptr) {
                next.push({curr_node->left, max(Max, curr_node->val)});
                curr_node->left = nullptr;
            }
        }
        return result;
    }
};