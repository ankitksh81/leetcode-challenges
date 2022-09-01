/*
	Count Good Nodes in Binary Tree
	https://leetcode.com/problems/count-good-nodes-in-binary-tree/
*/

// Solution 1: DFS

class Solution {
public:
    int good = 0;
    
    void dfs(TreeNode* node, int mx_ele){
        if(node->val >= mx_ele){
            good++;
        }
        if(node->left){
            dfs(node->left, max(node->val, mx_ele));
        }
        if(node->right){
            dfs(node->right, max(node->val, mx_ele));
        }
    }
    
    int goodNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        dfs(root, INT_MIN);
        return good;
    }
};


// Solution 2: BFS

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