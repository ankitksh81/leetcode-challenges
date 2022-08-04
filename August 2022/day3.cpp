/*
	My Calendar I
	https://leetcode.com/problems/my-calendar-i/
*/

// Solution 1: Hashmap

class MyCalendar {
    map<int, int> schedule;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = schedule.upper_bound(start);
        if(it != schedule.end()) {
            if(it->first < end) {
                return false;
            }
        }
        if(it != schedule.begin()) {
            it--;
            if(it->second > start) {
                return false;
            }
        }
        schedule[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


// Solution 2: Balanced Tree

class MyCalendar {
private:
    struct Node {
        int start;
        int end;
        Node* left;
        Node* right;
        
        Node(int s, int e): start(s), end(e), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    bool insert(Node* node) {
        if(root == nullptr) {
            root = node;
            return true;
        }
        
        Node* cur = root;
        while(true) {
            if(check_overlaps(cur, node)) {
                return false;
            }
            
            if(isLessThan(cur, node)) {
                if(cur->left == nullptr) {
                    cur->left =  node;
                    return true;
                }
                else {
                    cur = cur->left;
                }
            }
            else {
                if(cur->right == nullptr) {
                    cur->right = node;
                    return true;
                }
                else {
                    cur = cur->right;
                }
            }
        }
    }
    
    bool check_overlaps(Node* cur, Node* node) {
        return !(node->start >= cur->end || node->end <= cur->start);
    }
    
    bool isLessThan(Node* cur, Node* node) {
        return (node->end <= cur->start);
    }
    
public:
    MyCalendar() {
        root = nullptr;
    }
    
    bool book(int start, int end) {
        return insert(new Node(start, end));
    }
};