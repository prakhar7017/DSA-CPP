class Solution {
  public:
    #define mod 1000000007
    vector<int> Series(int n) {
        vector<int>ans;
        int prev=0;
        int curr=1;
        int s;
        ans.push_back(prev);
        ans.push_back(curr);
        for(int i=2;i<=n;i++){
            s=(prev+curr) % mod;
            ans.push_back(s);
            prev=curr%mod;
            curr=s%mod;
        }
        return ans;
    }
};

// time complexity:O(n)
// space complexity:O(1)