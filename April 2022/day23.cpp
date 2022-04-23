/*
	Encode and Decode TinyURL
	https://leetcode.com/problems/encode-and-decode-tinyurl/
*/

// Solution 1: Using Random Numbers

class Solution {
    string link = "http://tinyurl.com/";
    unordered_map<string, string> mp;
    
    string getKey() {
        const int MAX = 1e9+7;
        int r = rand() % MAX;
        return to_string(r);
    }
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = getKey();
        mp[link + key] = longUrl;
        return link + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

// Solution 2: Using Hashmap size

class Solution {
	unordered_map<string, string> mp;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int n = mp.size();
        string key = to_string(n + 1);
        mp[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));