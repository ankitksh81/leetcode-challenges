// Problem link: https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/613/week-1-august-1st-august-7th/3871/


// Solution:

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

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
		}
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