// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3903/


// Solution:

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
	long res = 0, total = 0, x;
	int sum(TreeNode* root) {
		if(root == nullptr) {
			return 0;
		}
		x = root->val + sum(root->left) + sum(root->right);
		res = max(res, x * (total - x));
		return x;
	}

    int maxProduct(TreeNode* root) {
    	total = sum(root), sum(root);
    	return res % (int)(1e9+7);
    }
};