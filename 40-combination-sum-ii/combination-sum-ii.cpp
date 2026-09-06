class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx, int target, vector<int>& v, vector<int>& candidates) {
        if(target<0) return;
        if(target == 0){
            ans.push_back(v);
        }

        for(int i=idx;i<candidates.size();i++){
            if( i>idx && candidates[i]==candidates[i-1]) continue;
            v.push_back(candidates[i]);
            solve(i+1,target-candidates[i],v,candidates);
            v.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        sort(begin(candidates),end(candidates));
        solve(0, target, v, candidates);
        return ans;
    }
};