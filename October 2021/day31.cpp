/*
    Flatten a multilevel doubly linked list
    https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/
*/

// Solution:

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) {
            return head;
        }
        
        Node* cur = head;
        stack<Node*> st;
        
        while(true) {
            while(cur->child != nullptr) {
                if(cur->next != nullptr) {
                    st.push(cur->next);
                }
                
                Node* temp = cur;
                cur->next = cur->child;
                cur->child = nullptr;
                cur = cur->next;
                cur->prev = temp;
            }
            if(cur->next != nullptr) {
                cur = cur->next;
            }
            else if(!cur->next && !st.empty()) {
                Node* temp = cur;
                cur->next = st.top();
                cur = cur->next;
                cur->prev = temp;
                st.pop();
            }
            else if(!cur->next && st.empty()) {
                break;
            }
        }
        return head;
    }
};