class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < arr.size(); i++)
            m[(arr[i]%k+k)%k]++; 
        for(auto x : m) {
            if(x.first!=0 && m[x.first]!=m[k-x.first]) return 0;
            if(x.first==0 && x.second%2==1) return 0;
        }
        return 1;
    }
};