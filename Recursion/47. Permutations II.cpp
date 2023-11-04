class Solution {
    private:
    void permuteUniqueHelper(vector<int>& nums,vector<vector<int>>&ans,int index){
        //base case
        if(index>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        //processing
        unordered_map<int,bool>visited;
        for(int j=index;j<nums.size();j++){
            if(visited.find(nums[j])!=visited.end()){
                continue;
            }
            visited[nums[j]]=true;
            swap(nums[index],nums[j]);
            permuteUniqueHelper(nums,ans,index+1);
            //backtrack
            swap(nums[index],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        permuteUniqueHelper(nums,ans,0);
        // set<vector<int>>st;
        // for(auto e:ans){
        //     st.insert(e);
        // }
        // ans.clear();
        // for(auto e:st){
        //     ans.push_back(e);
        // }
        return ans;
    }
};

// time complexity: O(k) where k is the number of valid permutations.