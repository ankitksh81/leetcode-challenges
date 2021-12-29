/*
    Populating next right pointers in each node
    https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

// Solution 1: 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                
                if(i < sz - 1) {
                    node->next = q.front();
                }
                
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};

// Solution 2:

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) {
            return root;
        }
        
        Node* leftMost = root;
        while(leftMost->left != nullptr) {

            Node* head = leftMost;
            while(head != nullptr) {
                
                head->left->next = head->right;
                
                if(head->next != nullptr) {
                    head->right->next = head->next->left;
                }   
                head = head->next;
            }   
            leftMost = leftMost->left;
        }
        
        return root;
    }
};