/*
    Insert delete getRandom O(1)
    https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

// Solution 1:

class RandomizedSet {
    unordered_set<int> mySet;
    unordered_set<int>::iterator it;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mySet.count(val) == 0) {
            mySet.insert(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mySet.count(val) != 0) {
            mySet.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int sz = mySet.size();
        int randomVal = rand() % sz;
        it = mySet.begin();
        advance(it, randomVal);
        
        return (*it);
    }
};

// Solution 2:

class RandomizedSet
{
    vector<int> v;
    unordered_map<int, int> mymap;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (mymap.find(val) != mymap.end())
            return false;

        v.push_back(val);
        mymap[val] = v.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {

        if (mymap.find(val) == mymap.end())
            return false;

        auto it = mymap.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mymap[v[it->second]] = it->second;
        mymap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return v[rand() % v.size()];
    }
};