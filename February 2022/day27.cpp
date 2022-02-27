/*
	Maximum Width of Binary Tree
	https://leetcode.com/problems/maximum-width-of-binary-tree/
*/

// Solution: BFS

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        int max_width = 0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int q_size = q.size();
            long min_idx = q.front().second;
            int first_idx, last_idx;
            
            for(int i = 0; i < q_size; i++) {
                long cur_idx = q.front().second - min_idx;
                TreeNode* cur_node = q.front().first;
                q.pop();
                
                if(i == 0) {
                    first_idx = cur_idx;
                }
                if(i == q_size - 1) {
                    last_idx = cur_idx;
                }
                
                if(cur_node->left != nullptr) {
                    q.push({cur_node->left, cur_idx * 2 + 1});
                }
                if(cur_node->right != nullptr) {
                    q.push({cur_node->right, cur_idx * 2 + 2});
                }
            }
            
            max_width = max(max_width, last_idx - first_idx + 1);
        }
        
        return max_width;
    }
};