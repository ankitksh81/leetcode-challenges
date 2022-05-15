/*
	Deepest Leaves Sum
	https://leetcode.com/problems/deepest-leaves-sum/
*/

// Solution: Recursion

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int sum = 0, maxDepth, curDepth;
        stack<pair<TreeNode*, int>> st; // node, depth;
        st.push({root, 0});
        
        while(!st.empty()) {
            pair<TreeNode*, int> p = st.top();
            st.pop();
            
            TreeNode* node = p.first;
            curDepth = p.second;
            
            if(!node->left && !node->right) {
                if(curDepth > maxDepth) {
                    maxDepth = curDepth;
                    sum = node->val;
                }
                else if(curDepth == maxDepth) {
                    sum += node->val;
                }
            }
            else {
                if(node->right) {
                    st.push({node->right, curDepth + 1});
                }
                if(node->left) {
                    st.push({node->left, curDepth + 1});
                }
            }
        }
        
        return sum;
    }
};