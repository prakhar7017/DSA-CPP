class Solution {
public:
    #define INF (1e9+1)
    int solve(vector<int>& arr1, vector<int>& arr2,int prev,int curr,map<pair<int,int>,int>&mp){
        // base case
        if(curr>=arr1.size()){
            return 0;
        }
        if(mp.find({prev,curr})!=mp.end()){
            return mp[{prev,curr}];
        }
        int op1=INF;
        if(prev<arr1[curr]){
            op1=0+solve(arr1,arr2,arr1[curr],curr+1,mp);
        }
        int op2=INF;
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        if(it!=arr2.end()){
            int index=it-arr2.begin();
            //arr1[curr]=arr2[index]; // it is modifying original array, so instead of modifying just pass the upper_bound of prev to next call
            op2=1+solve(arr1,arr2,arr2[index],curr+1,mp);
        }
        return mp[{prev,curr}]=min(op1,op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int>mp;
        int ans=solve(arr1,arr2,-1,0,mp);
        return ans == INF ? -1 : ans;
    }
};