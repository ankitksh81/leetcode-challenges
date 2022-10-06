/*
        Time Based Key-Value Store
        https://leetcode.com/problems/time-based-key-value-store/description/
*/

// Solution: Hashmap + Binary Search

class TimeMap {
    unordered_map<string, map<int, string>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        auto itr = mp[key].upper_bound(timestamp);
        if (itr == mp[key].begin()) {
            return "";
        }

        return prev(itr)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
