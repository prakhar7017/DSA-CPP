class Solution {
    private:
    void combinationSumHelper(vector<vector<int>>&ans,vector<int>& candidates,
    vector<int>&v,int target,int index){
        //base case
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0){
            return;
        }
        //processing
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            v.push_back(candidates[i]);
            combinationSumHelper(ans,candidates,v,target-candidates[i],i+1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans; 
        vector<int>v;
        combinationSumHelper(ans,candidates,v,target,0);
        return ans; 
    }
};