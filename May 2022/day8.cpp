/*
	Flatten Nested List Iterator
	https://leetcode.com/problems/flatten-nested-list-iterator/
*/

// Solution 1: Recursion

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> res;
    int pos;
    
    void flattenAll(vector<NestedInteger> &nestedList) {
        for (NestedInteger nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                res.push_back(nestedInteger.getInteger());
            }
            else {
                flattenAll(nestedInteger.getList());
            }
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        pos = 0;
        flattenAll(nestedList);
    }
    
    int next() {
        return res[pos++];
    }
    
    bool hasNext() {
        return (pos < res.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// Solution 2: Stack with address of NestedIntegers

class NestedIterator {
    stack<NestedInteger*> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size()-1; i >= 0; i--) {
            st.push(&nestedList[i]);
        }
    }
    
    int next() {
        int val = st.top()->getInteger();
        st.pop();
        return val;
    }
    
    bool hasNext() {
        while (!st.empty()) {
            NestedInteger *ptr = st.top();
            if (ptr->isInteger()) {
                return true;
            }
            
            vector<NestedInteger> &curList = ptr->getList();
            st.pop();
            
            for (int i = curList.size()-1; i >= 0; i--) {
                st.push(&curList[i]);
            }
        }
        
        return false;
    }
};

// Solution 3: Stacks of iterators

class NestedIterator {
    stack<vector<NestedInteger>::iterator> begins, ends;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }
    
    int next() {
        int val = begins.top()->getInteger();
        begins.top()++;
        return val;
    }
    
    bool hasNext() {
        while (!begins.empty()) {
            vector<NestedInteger>::iterator itr = begins.top();
            if (itr == ends.top()) {
                begins.pop();
                ends.pop();
                
                if(!begins.empty()) {
                    begins.top()++;
                }
            }
            else if(itr->isInteger()) {
                return true;
            }
            else {
                vector<NestedInteger>& curList = itr->getList();
                begins.push(curList.begin());
                ends.push(curList.end());
            }
        }
        
        return false;
    }
};