/*
	Clone Graph
	https://leetcode.com/problems/clone-graph/
*/

// Solution 1: DFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) {
            return node;
        }
        
        if(visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        Node* cloneNode = new Node(node->val, vector<Node*>());
        visited[node] = cloneNode;
        
        for(auto neighbor: node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }
};