class Solution {
public:
    void solveUsingRec(int index,int prev,vector<int>&temp,vector<int>&result,vector<int>&nums){
        if(index>=nums.size()){
            if(temp.size()>result.size()){
                result=temp;
            }
            return;
        }
        if( prev==-1 || nums[index]%prev==0 ){
            temp.push_back(nums[index]);
            solveUsingRec(index+1,nums[index],temp,result,nums);
            // backtrack
            temp.pop_back();
        }

        solveUsingRec(index+1,prev,temp,result,nums);
    }
    vector<int>solveUsingBottomUp(vector<int>& nums){
        int n=nums.size();
        sort(begin(nums),end(nums));
        vector<int>t(n,1);
        vector<int>prev_index(n,-1);
        int maxLen=1;
        int last_choosen_index=0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(t[i]<t[j]+1){
                        t[i]=t[j]+1;
                        prev_index[i]=j;
                    }

                    if(t[i]>maxLen){
                        maxLen=t[i];
                        last_choosen_index=i;
                    }
                }
            }
        }

        vector<int>ans;
        while(last_choosen_index>=0){
            ans.push_back(nums[last_choosen_index]);
            last_choosen_index=prev_index[last_choosen_index];
        }
        return ans;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // vector<int>result;
        // vector<int>temp;
        // int prev=-1;
        // sort(begin(nums),end(nums));
        // solveUsingRec(0,prev,temp,result,nums);
        return solveUsingBottomUp(nums);
    }
};