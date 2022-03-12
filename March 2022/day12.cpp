/*
	Copy List with Random Pointer
	https://leetcode.com/problems/copy-list-with-random-pointer/
*/

// Solution: 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) {
            return nullptr;
        }
        
        Node* cur = head;
        while(cur) {
            Node* node = new Node(cur->val);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        cur = head;
        while(cur) {
            if(cur->random) {
                cur->next->random = cur->random->next;
            }
            else {
                cur->next->random = nullptr;
            }
            cur = cur->next->next;
        }
        
        // a->a'->b->b'->null
        Node* orig = head;
        Node* copy = head->next;
        Node* res = copy;
        
        while(orig) {
            orig->next = orig->next->next;
            if(copy->next) {
                copy->next = copy->next->next;
            }
            else {
                copy->next = nullptr;
            }
            copy = copy->next;
            orig = orig->next;
        }
        return res;
    }
};