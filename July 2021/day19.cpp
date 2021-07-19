/* Day 19
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3819/
*/


// Solution 1:

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr or root == p or root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != nullptr and right != nullptr) {
            return root;
        }
        else {
            if(left == nullptr) {
                return right;
            }
            return left;
        }
    }
};


// Solution 2:

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) {
            return nullptr;
        }
        else if(p->val < root->val and q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val > root->val and q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
            return root;
    }
};
