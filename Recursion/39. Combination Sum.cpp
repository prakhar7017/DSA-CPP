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
            v.push_back(candidates[i]);
            combinationSumHelper(ans,candidates,v,target-candidates[i],i);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) { 
        vector<vector<int>>ans; 
        vector<int>v;
        combinationSumHelper(ans,candidates,v,target,0);
        return ans; 
    }
};

// time complexity of the above solution is O(k) where k is the number of valid permutations.