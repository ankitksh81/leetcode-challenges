/* Day 30:
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/612/week-5-july-29th-july-31st/3832/
*/

// Solution 1:

class MapSum {
    map<string, int> m;
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
        auto it = m.find(key);
        if(it != m.end()){
            m[key] = val;
        }
        else{
            m.insert({key, val});
        }
    }

    int sum(string prefix) {
        int ans = 0;
        for (auto itr = m.lower_bound(prefix); itr != m.end() && itr->first.compare(0, prefix.size(), prefix) == 0; ++itr){
            ans += itr->second;
        }
        return ans;
    }
};



// Solution 2:

class MapSum {
public:
    /** Initialize your data structure here. */
    struct Node {
        int val;
        Node** next;
        Node() {
            val = -1;
            next = new Node*[26]();
        }
    };
    Node* root = nullptr;
    MapSum() {
        root = new Node();
    }

    void insert(string key, int val) {
        Node* cur = root;
        for(int i=0;i<key.size();i++) {
            int idx = key[i]-97;
            if(!cur->next[idx])
                cur->next[idx] = new Node();
            cur = cur->next[idx];
        }
        cur->val = val;
    }

    int sum(string prefix) {
        Node* cur = root;
        for(int i=0;i<prefix.size();i++) {
            int idx = prefix[i]-97;
            if(!cur->next[idx])
                return 0;
            cur = cur->next[idx];
        }
        return traverse(cur);
    }
private:
    int traverse(Node* root) {
        if(!root)
            return 0;
        int s = root->val==-1? 0:root->val;
        for(int i=0;i<26;i++)
            s+=traverse(root->next[i]);
        return s;
    }
};
