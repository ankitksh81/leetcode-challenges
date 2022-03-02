/*
	Clone N-ary Tree
	https://leetcode.com/problems/clone-n-ary-tree/
*/

// Solution 1: DFS

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
    Node* cloneTree(Node* root) {
        if(root == nullptr) {
            return root;
        }
        
        Node* copy = new Node(root->val, vector<Node*>());
        for(auto child : root->children) {
            copy->children.push_back(cloneTree(child));
        }
        
        return copy;
    }
};

// Solution 2: BFS

/*
class Node {
public:
    int val;
    vector<Node*> children;
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(root == nullptr) {
            return root;
        }
        
        Node* copy = new Node(root->val, vector<Node*>());
        queue<pair<Node*, Node*>> q;
        q.push({root, copy});
        
        while(!q.empty()) {
            Node* origNode = q.front().first;
            Node* copyNode = q.front().second;
            q.pop();
            
            for(auto child : origNode->children) {
                Node* newChild = new Node(child->val, vector<Node*>());
                copyNode->children.push_back(newChild);
                q.push({child, newChild});
            }
        }
        
        return copy;
    }
};