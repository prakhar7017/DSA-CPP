class Solution {
public:
    typedef pair<int,int>P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<P>items(begin(mp),end(mp));
        sort(begin(items),end(items),[](P& a, P& b){
            return a.second > b.second;
        });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(items[i].first);
        }
        return ans;
    }
};