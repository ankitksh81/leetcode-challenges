/*
	Maximum XOR of Two Numbers in an Array
	https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
*/

// Solution:

class TrieNode {
public:
    TrieNode *child[2];
    
    TrieNode() {
        this->child[0] = nullptr;
        this->child[1] = nullptr;
    }
};

class Solution {
    TrieNode *newNode;
    
    void insert(int x) {
        TrieNode *t = newNode;
        bitset<32> bs(x);
        
        for(int j = 31; j >= 0; j--) {
            if(!t->child[bs[j]]) {
                t->child[bs[j]] = new TrieNode();
            }
            t = t->child[bs[j]];
        }
    }
    
public:
    int maxXOR(int x) {
        TrieNode *t = newNode;
        bitset<32> bs(x);
        int ans = 0;
        for(int j = 31; j >= 0; j--) {
            if(t->child[!bs[j]]) {
                ans += (1 << j);
                t = t->child[!bs[j]];
            }
            else {
                t = t->child[bs[j]];
            }
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        newNode = new TrieNode();
        for(auto &x: nums) {
            insert(x);
        }
        
        int ans = 0;
        for(auto x: nums) {
            ans = max(ans, maxXOR(x));
        }
        return ans;
    }
};