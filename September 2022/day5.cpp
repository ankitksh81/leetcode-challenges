/*
	N-ary Tree Level Order Traversal
	https://leetcode.com/problems/n-ary-tree-level-order-traversal/
*/

// Solution: BFS

class Solution {
public:
	void levelOrderTraversal(Node* root, vector<vector<int>>& ans) {
		queue<Node*> q;
		q.push(root);

		while(!q.empty()) {
			int size = q.size();
			vector<int> level;

			for(int i = 0; i < size; i++) {
				auto it = q.front();
				q.pop();

				level.push_back(it->val);

				for(auto x: it->children) {
					q.push(x);
				}
			}

			ans.push_back(level);
		}a
	}

	vector<vector<int>> levelOrder(Node *root) {
		if(root == nullptr) {
			return {};
		}
		vector<vector<int>> ans;
		levelOrderTraversal(root, ans);
		return ans;
	}
};