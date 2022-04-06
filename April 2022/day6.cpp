/*
	3Sum With Multiplicity
	https://leetcode.com/problems/3sum-with-multiplicity/
*/

// Solution: Two Pointer + Sorting

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9+7;
        unordered_map<int, int> freq;
        for(int x : arr) {
            freq[x]++;
        }
        sort(arr.begin(), arr.end());
        long ans = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            int T = target - arr[i];
            int j = i + 1, k = arr.size()-1;
            
            while(j < k) {
                if(arr[j] + arr[k] < T) {
                    j++;
                }
                else if(arr[j] + arr[k] > T) {
                    k--;
                }
                else if(arr[j] != arr[k]) {
                    int left = 1, right = 1;
                    while(j+1 < k && arr[j] == arr[j+1]) {
                        left++;
                        j++;
                    }
                    while(k-1 > j && arr[k] == arr[k-1]) {
                        right++;
                        k--;
                    }
                    
                    ans += left * right;
                    ans = ans % MOD;
                    j++;
                    k--;
                }
                else {
                    ans += (k - j + 1) * (k - j) / 2;
                    ans = ans % MOD;
                    break;
                }
            }
        }
        
        return (int)ans;
    }
};