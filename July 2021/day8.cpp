/* Day 8
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3807/
*/

// Solution 1

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[n+1][m+1];
        int mx = 0;

        for(int i = 0; i < n+1; i++) {
            for(int j = 0; j < m+1; j++) {
                if(i == 0 or j == 0) {
                    dp[i][j] = 0;
                }
                else if(nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    mx = max(mx, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return mx;
    }
};


// Solution 2

#define MAXN 5000
class Solution {
public:
    int last=0,sz=0;
    int len[MAXN],nxt[MAXN],ch[MAXN][105];
    void add(int c){
        int p=last,u=sz++;len[u]=len[p]+1;
        while(p!=-1&&!ch[p][c]){ch[p][c]=u;p=nxt[p];}
        if(p==-1)nxt[u]=0;
        else{
            int q=ch[p][c];
            if(len[p]+1==len[q])nxt[u]=q;
            else{
                int n=sz++;
                len[n]=len[p]+1;
                nxt[n]=nxt[q];
                memcpy(ch[n],ch[q],sizeof(ch[q]));
                while(p!=-1&&ch[p][c]==q){ch[p][c]=n;p=nxt[p];}
                nxt[u]=nxt[q]=n;
            }
        }
        last=u;
    }
    int findLength(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size(),res=0;
        nxt[0]=-1;sz++;
        for(int i=0;i<n;i++)
            add(a[i]);
        int u=0,l=0,p=0;
        for(int i=0;i<m;i++){
            int c=b[i];
            while(u&&!ch[u][c]){
                u=nxt[u];
                l=len[u];
            }
            if(ch[u][c]){
                u=ch[u][c];
                l++;
            }
            if(l>res){
                res=l;
                p=i;
            }
        }
        cout<<last;
        return res;
    }
};
