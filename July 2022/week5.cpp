/*
	Flatten 2D Vector
	https://leetcode.com/problems/flatten-2d-vector/
*/

// Solution: Two Pointers

class Vector2D {
    vector<vector<int>> v;
    int outer = 0, inner = 0;
    
    void advanceToNext() {
        while(outer < v.size() && inner == v[outer].size()) {
            inner = 0;
            outer++;
        }
    }
    
public:
    Vector2D(vector<vector<int>>& vec) {
        v = vec;
    }
    
    int next() {
        hasNext();
        return v[outer][inner++];
    }
    
    bool hasNext() {
        advanceToNext();
        return outer < v.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */