/*
	Design HashMap
	https://leetcode.com/problems/design-hashmap/
*/

// Solution 1: Using vector

class MyHashMap {
    vector<int> table;
public:
    MyHashMap() {
        table.assign(1000005, -1);
    }
    
    void put(int key, int value) {
        table[key] = value;
    }
    
    int get(int key) {
        return table[key];
    }
    
    void remove(int key) {
        table[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// Solution 2:

class MyHashMap {
    vector<vector<pair<int, int>>> vec ;
    
    int Hashing(int key) {
        return key % 1000;
    }
    
public:
    MyHashMap() {
        const int size = 1e3 + 3;
        vec.resize(size);
    }
    
    void put(int key, int value) {
        bool found = true;
        int idx = Hashing(key);
        
        for(auto &i : vec[idx]) {
            if(i.first == key) {
                i.second = value;
                found = false;
                break;
            }
        }
        
        if(found)
            vec[Hashing(key)].push_back({key, value});
        
    }
    
    int get(int key) {
        int idx = Hashing(key);
        
        for(auto i : vec[idx]) {
            if(i.first == key) {
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx = Hashing(key);
        for(auto & i : vec[idx]) {
            if(i.first == key) {
                i.second = -1;
            }
        }
    }
};