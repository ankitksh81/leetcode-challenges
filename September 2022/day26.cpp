/*
        Satisfiability of Equality Equations
        https://leetcode.com/problems/satisfiability-of-equality-equations/
*/

// Solution: Disjoint Set Union

class UF {
public:
    vector<int> parent;
    
    UF() {
        for(int i = 0; i < 26; i++) {
            parent.push_back(i);
        }
    }
    
    int find(int a) {
        if(parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    
    void join(int a, int b) {
        parent[a] = b;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf;
        
        for(auto eq : equations) {
            if(eq[1] == '=') {
                int x = uf.find(eq[0] - 'a');
                int y = uf.find(eq[3] - 'a');
                
                if(x != y) {
                    uf.join(x, y);
                }
            }
        }
        
        for(auto eq : equations) {
            if(eq[1] == '!') {
                int x = uf.find(eq[0] - 'a');
                int y = uf.find(eq[3] - 'a');
                
                if(x == y) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
