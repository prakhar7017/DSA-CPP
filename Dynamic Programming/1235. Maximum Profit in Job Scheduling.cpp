class Solution {
    private:
    int getNextJobIndex(vector<vector<int>> &v,int l,int target){
        int r=v.size()-1;

        int result=r+1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid][0]>=target){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>> &v,int i){
        //base case
        if(i>=v.size()) return 0;

        if(memo[i]!=-1){
            return memo[i];
        }

        int next=getNextJobIndex(v,i+1,v[i][1]);
        int include=v[i][2]+solve(v,next);
        int exclude=solve(v,i+1);

        return memo[i]=max(include,exclude);
    }
public:
    int memo[50001];
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        memset(memo,-1,sizeof(memo));

        vector<vector<int>> v(n,vector<int>(3,0));

        for(int i=0;i<n;i++){
            v[i][0]=startTime[i];
            v[i][1]=endTime[i];
            v[i][2]=profit[i];
        }

        auto mycomp=[&](auto& v1,auto& v2){
            return v1[0]<=v2[0];
        };
        sort(v.begin(),v.end(),mycomp);
        int i=0;

        return solve(v,i);
    }
};

// time complexity: O(nlogn)

